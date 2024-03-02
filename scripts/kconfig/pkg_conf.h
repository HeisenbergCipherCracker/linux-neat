#ifndef REPO_GET_H
#define REPO_GET_H
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to write data to a file
size_t write_callback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void download_repo(const char* url_repo) {
    CURL *curl;
    FILE *output_file;

    curl = curl_easy_init();
    if (curl) {
        output_file = fopen("repo.tar.gz", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url_repo);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(output_file);
    }
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