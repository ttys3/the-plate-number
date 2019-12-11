/**
 * the plate number generator
 * https://www.tutorialspoint.com/compile_c_online.php
 * https://repl.it/languages/c
 * https://www.onlinegdb.com/online_c_compiler
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *thePlateNumber = "::TPL__PLACEHOLDER__";
#define DECODE 0
#define KEY 2

int main(int argc , char *argv[] ) {
    FILE * fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        perror("open source file err");
        exit(-2);
    }

    if (DECODE) {
        for (char *c=thePlateNumber; *c != '\0'; c++) {
            printf("%c", (*c)^ KEY);
        }
        printf("\n");
        exit(0);
    }

    char line[1024] = {'\0'};

    char *s;
    do {
        s = fgets(line, sizeof(line), fp);
        if (s != NULL ) {
            if (strstr(line, "char *thePlateNumber = \"") && NULL == strstr(line, "strstr")) {
                printf("char *thePlateNumber = \"");
                for (char *c=thePlateNumber; *c != '\0'; c++) {
                    char the_code = (*c)^ KEY;
                    if (the_code == '"' || the_code == '\\') {
                        printf("\\");
                    }
                    printf("%c", (*c)^ KEY);
                }
                printf("\";\n");
            } else if (strstr(line, "#define DECODE 0") && NULL == strstr(line, "strstr")) {
                time_t timer;
                char s[30];
                struct tm* tm_info;
                time(&timer);
                tm_info = localtime(&timer);
                strftime(s, 30, "%Y-%m-%d %H:%M:%S %Z", tm_info);
                printf("%c%c CODE GENERATED ON %s\n\n", '/', '/', s);
                printf("%s\n", "#define DECODE 1");
            } else {
                printf("%s", line);
            }
        } else if ( !feof(fp) ) {
            perror("read source file err");
            exit(-1);
        }
    } while (!feof(fp));

    fclose(fp);
    return 0;
}
