#include "utils.h"
#define size 5000
#define vector_size 500
#define size_sir 50
#define size_matrice 100

void SolveTask3() {
    char *text = NULL, *text2 = NULL, *text3 = NULL, *p = NULL;
    char *sir = NULL, *sir2 = NULL, **c = NULL, *s = NULL, *space = " ";
    char **matrice = NULL;

    sir = malloc(size_sir);
    sir2 = malloc(size_sir);

    int contor = 0, poz = 0, i = 0, j = 0, vector[vector_size], len = 0;

    text = malloc(size);
    text2 = malloc(size);
    text3 = malloc(size);
    scanf("\n");
    fgets(text, size, stdin);
    strncpy(text3, text, strlen(text));

    for (i = 0; i < vector_size; i++) {
        vector[i] = 1;
    }

    while (strncmp(text + strlen(text) - 1, "\n", 1) == 0) {
        scanf("\n");
        strncpy(text2, text, strlen(text));
        fgets(text, size, stdin);
        if (strncmp(text, text2, strlen(text)) == 0) {
            break;
        }
        strncat(text3, text, strlen(text));
    }
    matrice = malloc(size);
    for (i = 0; i < size; i++) {
        matrice[i] = malloc(size_matrice);
    }
    strncpy(text2, text3, strlen(text3));
    p = strtok(text3, " ,.!;\n");

    len = (int)strlen(text2) - (int)strlen(p) - 1;
    strncpy(text, text2 + strlen(p) + 1, len);

    len = (int)strlen(p);
    strncpy(sir, p, len);
    strncat(sir, space, 1);

    p = strtok(NULL, " ,.!;\n");
    strncat(sir, p, strlen(p));

    len = (int)strlen(sir);
    strncpy(matrice[poz], sir, len + 1);

    poz++;
    contor = 0;

    len = (int)strlen(text);
    strncpy(text2, text, len);

    len = (int)strlen(p);
    strncpy(sir2, p, len);

    len = (int)strlen(text2) - (int)strlen(p);
    strncpy(text, text2 + (int)strlen(p), len);

    p = strtok(NULL, " ,.!;\n");
    while (p) {
        contor = 0;

        len = (int)strlen(sir2);
        strncpy(sir, sir2, len + 1);
        strncat(sir, space, 1);

        len = (int)strlen(p);
        strncat(sir, p, len);

        s = strstr(text2, sir);
        while (s) {
            contor++;

            len = (int)strlen(s) - (int)strlen(sir);
            strncpy(text2, s + (int)strlen(sir) + 1, len);
            s = strstr(text2, sir);
        }

        len = (int)strlen(text);
        strncpy(text2, text, len);

        len = (int)strlen(text2) - (int)strlen(sir2);
        strncpy(text, text2 + (int)strlen(sir2), len);

        len = (int)strlen(p);
        strncpy(sir2, p, len + 1);

        contor = 1;
        for (i = 0; i < poz; i++) {
            if (strcmp(sir, matrice[i]) == 0) {
                contor++;
                vector[i] = vector[i] + 1;
            }
        }
        if (contor == 1) {
            len = (int)strlen(sir);
            strncpy(matrice[poz], sir, len + 1);
            poz++;
        }
        p = strtok(NULL, " ,.!;\n");
    }
    printf("%d\n", poz);
    for (i = 0; i < poz; i++) {
        printf("%s %d\n", matrice[i], vector[i]);
    }
}
