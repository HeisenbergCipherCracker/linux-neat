#ifndef PKG_MANAGER_INIT_H
#define PKG_MANAGER_INIT_H
#include "pkg_conf.h"
#include <stdio.h>
#include <stdlib.h>

void pkg_manager_init(void) {
    char* repos[] = {"https://github.com/HeisenbergCipherCracker/sqlgo.git"};
    int counts = sizeof(repos) / sizeof(repos[0]);
    start:
        for (int i = 0; i < counts; i++) {
            char* current_rep = repos[i];
            repo_init_keyword(current_rep);
        }
}

#endif