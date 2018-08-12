#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

void help(){
    printf("\n cd - new directory");
    printf("\n ls - show directory");
    printf("\n help - show commands list");
    printf("\n exit - terminate\n\n");
}

void PrintDir(char *cdir){
    DIR *dp = opendir(cdir);
    printf(cdir);
    printf("\n");
    struct dirent *ep;
    if (dp == NULL){
        printf("Null");
    }
    if (dp != NULL) {
        while ((ep = readdir(dp))) {
            if (ep->d_name[0] != '.')
                printf("%s ", ep->d_name);
            printf("\n");
        }
    }
    closedir(dp);
    return;
}

int main(int argc, char *argv[]) {
    char temparg[30] = "";
    char tempdir[30] = "";
    bool EM = false;
    char dir_path[512];
    argv[3] = getcwd(dir_path, sizeof(dir_path));
    switch(argc){
        case 2:
            if (strcmp(argv[1], "ls") == 0) {
                PrintDir(argv[3]);
            }
            break;
        case 3:
            if (strcmp(argv[1], "ls") == 0) {
                PrintDir(argv[2]);
            }
            break;
    }

    while (!EM) {
        printf("\n");
        printf(argv[3]);
        printf("\n");
        argv[2] = gets(temparg);
        if (strcmp(argv[2], "cd") == 0) {
            argv[3] = gets(tempdir);
            printf("\n");
        } else if (strcmp(argv[2], "ls") == 0) {
            PrintDir(argv[3]);
            printf("\n");
        } else if (strcmp(argv[2], "exit") == 0) {
            EM = true;
        } else if (strcmp(argv[2], "help") == 0) {
            help();
        } else {
            printf("try again\n");
        }
    }


    return -1;
}
