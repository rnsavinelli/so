/*
 * ex01.c
 *
 * Copyright 2021 Roberto Nicolás Savinelli <rsavinelli@frba.utn.edu.ar>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

#include <stdio.h>
#include <stdlib.h>

size_t string_len(const char *a) {
    if(a == NULL) return 0;
    else {
        size_t length = 0;
        while(a[length] != '\0') length++;
        return length;
    }
}


int str_len(const char *str) {
    const char *s;
    for(s = str; *s; ++s);
    return (s - str);
}

char* str_cat(const char *a, const char *b) {
    size_t size_a = str_len(a), size_b = str_len(b);

    char *s = (char *) calloc(sizeof(char), str_len(a) + str_len(b) + 1ul);

    for(int i = 0; i < size_a; i++)
        s[i] = a[i];

    for(int i = 0; i < size_b; i++)
        s[size_a + i] = b[i];

    s[str_len(a) + str_len(b)] = '\0';

    return s;
}

void str_cat_dyn(const char *a, const char *b, char **c) {
    *c = str_cat(a, b);
}

int main(int argc, char *argv[]) {
    char * str1 = "Hello ";
    char * str2 = "World!";

    char * str3 = NULL;

    str3 = str_cat(str1, str2);
    printf("%s\n", str3);
    free(str3);

    str_cat_dyn(str1, str2, &str3);
    printf("%s\n", str3);
    free(str3);

    return 0;
}
