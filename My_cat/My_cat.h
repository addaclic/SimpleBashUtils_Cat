#ifndef MY_CAT_H
#define MY_CAT_H

#ifdef __linux__
#define LETTERS_CASE "benstvET"
#else
#define LETTERS_CASE "+benstvET"
#endif

#include <getopt.h>
#include <stdio.h>

typedef struct {
  char e;
  char n;
  char s;
  char t;
  char v;
  char b;
} my_cat_opt;

int parse_opts(int, char *[], my_cat_opt *);
void output_file(int, char *[], my_cat_opt);
void print_text(FILE *, my_cat_opt);

#endif  // MY_CAT_H