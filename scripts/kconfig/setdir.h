#ifndef SETDIR_H
#define SETDIR_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


static int is_dir(char* dir) {
    char *directory_path = dir;

    if (access(directory_path, F_OK) == 0) {
        return 1;
    } else {
        return 0;
    }


}


void setdir(char* dir) {
    if (is_dir(dir)) {
        chdir(dir);
    } else {
        fprintf(stderr, "Error: %s is not a directory.\n", dir);
        exit(1);
    }
}
#endif