#ifndef PKG_CONFIG_H
#define PKG_CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "_pkg_conf.h"
#define CONF_FILE_NAME "pkg_config.conf"
#define PKG_PATH "package"

bool path_exists(const char* path) {
    return access(path, F_OK) != -1;
}


void download_repo_config(const char* url_repo) {
    char command[1000];
    if (path_exists(PKG_PATH)) {
        snprintf(command, sizeof(command), "git clone %s %s", url_repo, PKG_PATH);
        return;
    }
    snprintf(command, sizeof(command), "git clone %s", url_repo);
    return;

}




#endif