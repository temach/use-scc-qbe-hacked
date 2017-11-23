/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/22/2017 12:27:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Artem Abramov (aa), tematibr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../qbe/all.h"

#include <stdio.h>

void artemfn (Fn *fn);
void artemdat (Dat *dat);

int main () {
  parse(stdin, "<stdin>", artemdat, artemfn);
  freeall();
}

