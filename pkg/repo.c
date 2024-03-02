#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("repos.conf", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char key[50];
    char value[100];

    while (fscanf(file, "%49s = \"%99[^\"]\"", key, value) == 2) {
        if (strcmp(key, "sqlgo") == 0) {
            printf("sqlgo = \"%s\"\n", value);
            break;
        }
    }

    fclose(file);

    return 0;
}