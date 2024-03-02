#ifndef REPO_GET_H
#define REPO_GET_H
#include <stdio.h>
#include <string.h>

char* repo_init_keyword() {
    FILE *file = fopen("repos.conf", "r");
    if (file == NULL) {
        perror("Error opening file\n");
    }

    char key[50];
    char value[100];

    while (fscanf(file, "%49s = \"%99[^\"]\"", key, value) == 2) {
        if (strcmp(key, "sqlgo") == 0) {
            printf("sqlgo = \"%s\"\n", value);
            return value;
            break;
        }
    }

    fclose(file);

}

#endif