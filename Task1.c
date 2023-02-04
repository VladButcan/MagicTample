#include "utils.h"
#define SIZE 130
void SolveTask1() {
    int N = 0, M = 0, pas = 1, contor = 0, pozitie = 0;
    char *s = NULL, *p = NULL, *t = NULL;
    char *max = NULL, *nr = NULL, *K = NULL, *revers = NULL;

    max = malloc(2);

    scanf("%d %d\n", &N, &M);

    int a[N][M], i = 0, j = 0;
    int len = 0, X = 0, ok = 0, d = 0, z = 0;
    K = malloc(1);

    int k = 0, n = 0, S = 0, temp = 0;

    nr = malloc(3);
// setam toata matricea cu valoarea 0
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] = 0;
        }
    }
// setam primul pas 1 pe pozitia [0][0]
    a[0][0] = pas;
    pas++;
    i = 0;
    j = 0;

    s = malloc(SIZE * sizeof(char));

    fgets(s, SIZE, stdin);

    p = strtok(s, " \n");
    t = (char *)malloc(strlen(p) + 1);
    revers = malloc(strlen(p) + 1);

    while (p) {
        t = (char *)realloc(t, strlen(p) + 1);
        if (strncmp(p, "a", 1) == 0) {
            contor = 1;

            strncpy(max, p + contor, 1);

            pozitie = 1;

            while (contor < strlen(p) - 1) {
                if (strncmp((p + contor + 1), max, 1) > 0) {
                    strncpy(max, p + contor + 1, 1);

                    pozitie = contor + 1;
                }
                contor++;
            }
            p = strtok(NULL, " \n");

            if (pozitie == 1) {
                j++;
                a[i][j] = pas;
                pas++;
            }
            if (pozitie == 2) {
                i--;
                a[i][j] = pas;
                pas++;
            }
            if (pozitie == 3) {
                j--;
                a[i][j] = pas;
                pas++;
            }
            if (pozitie == 4) {
                i++;
                a[i][j] = pas;
                pas++;
            }
        } else {
            if (strncmp(p, "b", 1) == 0) {
                K = realloc(K, strlen(p) + 1);
                revers = realloc(revers, strlen(p) + 1);

                strncpy(nr, p + strlen(p) - 2, 2);

                X = atoi(nr);

                strncpy(K, p + 1, strlen(p));
                strncpy(revers, p + 1, strlen(p));

                len = (int)strlen(revers);

                for (z = 0; z < len/2; z++) {
                    temp = (int)revers[z];
                    revers[z] = revers[len - z - 1];
                    revers[len - z - 1] = (char)temp;
                }

                d = 2;
                ok = 0;

                while (X > 1) {
                    if (X % d == 0) {
                        while (X % d == 0) {
                            X = X / d;
                            ok++;
                        }
                    }
                    d++;
                }
                contor = 1;

                strncpy(max, p + contor, 1);

                pozitie = 1;

                while (contor < strlen(p) - 1) {
                    if (strncmp((p + contor + 1), max, 1) > 0) {
                        strncpy(max, p + contor + 1, 1);

                        pozitie = contor + 1;
                    }
                    contor++;
                }
                p = strtok(NULL, " \n");

                if (ok == 1 && strncmp(K, revers, strlen(K)) == 0) {
                    j--;
                    a[i][j] = pas;
                    pas++;
                }
                if (ok != 1 && strncmp(K, revers, strlen(K)) == 0) {
                    j++;
                    a[i][j] = pas;
                    pas++;
                }
                if (ok == 1 && strncmp(K, revers, strlen(K)) != 0) {
                    i--;
                    a[i][j] = pas;
                    pas++;
                }
                if (ok != 1 && strncmp(K, revers, strlen(K)) != 0) {
                    i++;
                    a[i][j] = pas;
                    pas++;
                }
            } else {
                if (strncmp(p, "c", 1) == 0) {
                    strncpy(max, p + 2, 1);
                    k = atoi(max);
                    strncpy(max, p + 1, 1);
                    n = atoi(max);
                    contor = 0;
                    S = 0;

                    while (contor < k) {
                        d = contor * k;
                        strncpy(max, p + 3 + d, 1);

                        if (contor * k < n) {
                            S = S + atoi(max);
                        } else {
                            while (d >= n) {
                                d = d % n;
                            }
                            strncpy(max, p + 3 + d, 1);

                            S = S + atoi(max);
                        }
                        contor++;
                    }

                    if (S % 4 == 0) {
                        j--;
                        a[i][j] = pas;
                        pas++;
                    }
                    if (S % 4 == 1) {
                        i--;
                        a[i][j] = pas;
                        pas++;
                    }
                    if (S % 4 == 2) {
                        j++;
                        a[i][j] = pas;
                        pas++;
                    }
                    if (S % 4 == 3) {
                        i++;
                        a[i][j] = pas;
                        pas++;
                    }
                    p = strtok(NULL, " \n");
                }
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
