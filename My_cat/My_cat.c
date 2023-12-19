#include "My_cat.h"

int main(int argc, char *argv[]) {
  my_cat_opt opt = {0};
  if (!(parse_opts(argc, argv, &opt))) {
    output_file(argc, argv, opt);
  }
  return 0;
}

int parse_opts(int argc, char *argv[], my_cat_opt *flags) {
  const struct option long_options[] = {
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {"number-nonblank", no_argument, NULL, 'b'},
      {0, 0, 0, 0}};
  char ret_char;
  while ((ret_char = getopt_long(argc, argv, LETTERS_CASE, long_options,
                                 NULL)) != -1) {
    switch (ret_char) {
      case 'e':
        flags->e = 1;
        flags->v = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 't':
        flags->t = 1;
        flags->v = 1;
        break;
      case 'b':
        flags->b = 1;
        break;
      default:
        fprintf(stderr, "cat: invalid option -- %c\n", ret_char);
        return 1;
    }
  }
  return 0;
}

void output_file(int argc, char *argv[], my_cat_opt flags) {
  FILE *file_name;
  for (int i = optind; i < argc; ++i) {
    if ((file_name = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
    } else {
      print_text(file_name, flags);
      fclose(file_name);
    }
  }
}

void print_text(FILE *file_name, my_cat_opt flags) {
  char simbol;
  int count_str = 1;
  char print_numb = 1;
  int count_slash_n = 1;
  while ((simbol = fgetc(file_name)) != EOF) {
    if (flags.s && simbol == '\n')
      ++count_slash_n;
    else
      count_slash_n = 0;
    if ((flags.n && print_numb && !flags.b && count_slash_n < 3) ||
        (flags.b && simbol != '\n' && print_numb)) {
      printf("%6d\t", count_str);
      ++count_str;
      print_numb = 0;
    }
    if (flags.t && simbol == '\t') {
      putchar('^');
      simbol = 'I';
    }
    if (flags.v &&
        ((simbol >= 0 && simbol <= 8) || (simbol >= 11 && simbol <= 31))) {
      putchar('^');
      simbol += 64;
    }
    if (flags.v && simbol == 127) {
      putchar('^');
      simbol -= 64;
    }
    if (count_slash_n < 3) {
      if (flags.e && simbol == '\n') putchar('$');
      putchar(simbol);
    }
    if (simbol == '\n') print_numb = 1;
  }
}
