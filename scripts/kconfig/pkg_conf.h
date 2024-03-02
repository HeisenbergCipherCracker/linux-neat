#ifndef REPO_GET_H
#define REPO_GET_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void download_repo(const char* url_repo) {
    char command[100];
    sprintf(command, "wget %s -O repo.tar.gz", url_repo);
    system(command);
}

char* repo_init_sqlgo_keyword() {
    FILE *file = fopen("repos.conf", "r");
    if (file == NULL) {
        perror("Error opening file\n");
    }

    char key[50];
    char value[100];

    while (fscanf(file, "%49s = \"%99[^\"]\"", key, value) == 2) {
        if (strcmp(key, "sqlgo") == 0) {
            printf("sqlgo = \"%s\"\n", value);
            download_repo(value);
            return value;
        }
    }

    fclose(file);
    return NULL;
}

#endif