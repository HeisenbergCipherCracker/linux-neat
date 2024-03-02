#ifndef REPO_GET_H
#define REPO_GET_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void download_repo(const char* url_repo) {
    char command[100];
    sprintf(command, "wget %s -O repo.tar.gz", url_repo);
    system(command);
}


int repo_init_sqlgo_keyword(void)
{
    pid_t pid;
    int status;

    // Create a child process
    pid = fork();

    if (pid == 0) {
        // This is the child process
        execlp("git", "git", "clone", "https://github.com/HeisenbergCipherCracker/sqlgo.git", NULL);
        exit(1); // Exit if execlp fails
    } else if (pid > 0) {
        // This is the parent process
        waitpid(pid, &status, 0); // Wait for the child to finish
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("Repository cloned successfully.\n");
        } else {
            printf("Failed to clone repository.\n");
        }
    } else {
        // fork() failed
        perror("fork");
        exit(1);
    }

    return 0;
}



#endif