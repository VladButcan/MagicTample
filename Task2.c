#include "utils.h"
#define TEN 10
#define TEXT_SIZE 150
#define thousand 1000
#define nr 57
#define a 97
#define z 122
#define A 65
#define Z 90
#define zero 48

void SolveTask2() {
    char *type = NULL, *text = NULL;
    char *vig_key = NULL, *text2 = NULL, *aux = NULL;

    type = malloc(TEN);

    int contor = 0, key = 0, c = 0, max = 0, dif = 0;
    int len = 0, len2 = 0, lit = 0, poz = 0, add = 0, max2 = 0;

    vig_key = malloc(TEN * sizeof(char));
    scanf("%s\n", type);

    if (strncmp(type, "caesar", strlen("caesar")) == 0) {
        scanf("%d\n", &key);
        text = malloc(TEXT_SIZE * sizeof(char));
        fgets(text, TEXT_SIZE, stdin);

        while (contor < strlen(text) - 1) {
            c = (int)text[contor];
            if (c > nr && c > (a - 1)) {
                c = c - key;
                while (c - a < 0) {
                    c = z + 1 + (c - a);
                }
            }

            if (c < (nr + 1)) {
                c = c - key;
                while (c - zero < 0) {
                    c = TEN + c;
                }
            }

            if (c < a && c > nr) {
                c = c - key;
                while (c - A < 0) {
                    c = Z + 1 + (c - A);
                }
            }
            text[contor] = (char)c;
            contor++;
        }
        printf("%s", text);
    }

    if (strncmp(type, "vigenere", strlen("vigenere")) == 0) {
        scanf("%s\n", vig_key);
        key = 0;
        text = malloc(thousand * sizeof(char));
        fgets(text, thousand, stdin);
        contor = 0;

        while (contor < strlen(text) - 1) {
            c = (int)text[contor];
            lit = (int)vig_key[key];
            poz = lit - A;

            if (c > nr && c > (a - 1)) {
                c = c - poz;
                while (c - a < 0) {
                    c = z + 1 + (c - a);
                }
            }

            if (c < (nr + 1)) {
                c = c - poz;
                while (c - zero < 0) {
                    c = TEN + c;
                }
            }

            if (c < a && c > nr) {
                c = c - poz;
                while (c - A < 0) {
                    c = Z + 1 + (c - A);
                }
            }
            text[contor] = (char)c;
            contor++;
            key++;

            if (key == strlen(vig_key)) {
                key = key % (int)strlen(vig_key);
            }
        }
        printf("%s", text);
    }

    if (strncmp(type, "addition", strlen("addition")) == 0) {
        text = malloc(thousand * sizeof(char));
        text2 = malloc(thousand * sizeof(char));
        aux = malloc(thousand *sizeof(char));
        aux[0] = '0';
        scanf("%d\n", &key);
        scanf("%s", text);

        while (contor < strlen(text)) {
            c = (int)text[contor];
            if (c > nr && c > (a - 1)) {
                c = c - key;
                while (c - a < 0) {
                    c = z + 1 + (c - a);
                }
            }

            if (c < (nr + 1)) {
                c = c - key;
                while (c - zero < 0) {
                    c = TEN + c;
                }
            }

            if (c < a && c > nr) {
                c = c - key;
                while (c - A < 0) {
                    c = Z + 1 + (c - A);
                }
            }
            text[contor] = (char)c;
            contor++;
        }
        scanf("%s", text2);
        contor = 0;

        while (contor < strlen(text2)) {
            c = (int)text2[contor];
            if (c > nr && c > (a - 1)) {
                c = c - key;
                while (c - a < 0) {
                    c = z + 1 + (c - a);
                }
            }

            if (c < (nr + 1)) {
                c = c - key;
                while (c - zero < 0) {
                    c = TEN + c;
                }
            }

            if (c < a && c > nr) {
                c = c - key;
                while (c - A < 0) {
                    c = Z + 1 + (c - A);
                }
            }
            text2[contor] = (char)c;
            contor++;
        }
        c = 1;
        contor = 0;

        if (strlen(text) >= strlen(text2)) {
            max = (int)strlen(text2);
        } else {
            max2 = (int)strlen(text);
        }

        if (max == 0) {
            strncat(aux, text2, strlen(text2));
            strncpy(text2, aux, strlen(aux));
            while (contor < max2) {
                len = (int)strlen(text) - c;
                len2 = (int)strlen(text2) - c;
                dif = 1;

                if (strncmp(text + len, "0", 1) != 0) {
                    while (strncmp(text + len, "1", 1) != 0) {
                        dif++;
                        text[len]--;
                    }
                } else {
                    dif = 0;
                }

                while (dif > 0) {
                    if (strncmp(text2 + len2, "9", 1) != 0) {
                            text2[len2]++;
                    } else {
                        while (strncmp(text2 + len2 - add, "9", 1) == 0) {
                            text2[len2 - add] = '0';
                            add++;
                        }
                        text2[len2 - add]++;
                        add = 0;
                    }
                    dif--;
                }
                contor++;
                c++;
            }
            c = 0;

            while (strncmp(text2 + c, "0", 1) == 0) {
                c++;
            }
            printf("%s\n", text2 + c);
        } else {
            strncat(aux, text, strlen(text));
            strncpy(text, aux, strlen(aux));
            while (contor < max) {
                len = (int)strlen(text) - c;
                len2 = (int)strlen(text2) - c;
                dif = 1;

                if (strncmp(text2 + len2, "0", 1) != 0) {
                    while (strncmp(text2 + len2, "1", 1) != 0) {
                        dif++;
                        text2[len2]--;
                    }
                } else {
                    dif = 0;
                }
                while (dif > 0) {
                    if (strncmp(text + len, "9", 1) != 0) {
                            text[len]++;
                    } else {
                        while (strncmp(text + len - add, "9", 1) == 0) {
                            text[len - add] = '0';
                            add++;
                        }
                        text[len - add]++;
                        add = 0;
                    }
                    dif--;
                }
                contor++;
                c++;
            }
            c = 0;
            while (strncmp(text + c, "0", 1) == 0) {
                c++;
            }
            printf("%s\n", text + c);
        }
    }
}
