#ifndef MY_CAT_H
#define MY_CAT_H

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

#endif  // MY_CAT_H