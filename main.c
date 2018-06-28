#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

void help(){
    printf("\n cd - change directory");
    printf("\n nd - new directory");
    printf("\n ls - show directory");
    printf("\n ls -R - recursive directory(beta)");
    printf("\n help - show comands list");
    printf("\n exit - terminate\n\n");
}


void RecDir(char *path, int flag) {
    DIR *dp = opendir(path);


    if(!dp) {
        perror(path);
        return;
    }

    struct dirent *ep;
    char newdir[512];

    printf("\n%s :\n" , path);

    while((ep = readdir(dp)))
        if(strncmp(ep->d_name, ".", 1))
            printf( "\t%s\n", ep->d_name);

    closedir(dp);
    dp = opendir(path);

    while((ep = readdir(dp))) if(strncmp(ep->d_name, ".", 1)) {
            if(flag && ep-> d_type == 4) {
                sprintf(newdir, "%s/%s", path, ep->d_name);
                RecDir(newdir, 1);
            }
        }

    closedir(dp);
}

void PrintDir(char *cdir){


    DIR *dp = opendir(cdir);

    struct dirent *ep;

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
    char cd[100] = "";
    char temps[30] = "";
    char arg[30] = "";
    bool EM = false;


    while (!EM) {
        gets(arg);
        if (strcmp(arg, "cd") == 0) {
            gets(temps);
            strcat(cd, temps);
            printf(cd);
            printf("\n");
        } else if (strcmp(arg, "ls") == 0) {
            PrintDir(cd);
        } else if (strcmp(arg, "ls -R") == 0) {
            RecDir(cd, 1);
        } else if (strcmp(arg, "exit") == 0) {
            EM = true;
        } else if (strcmp(arg, "nd") == 0) {
            gets(cd);
        } else if (strcmp(arg, "help") == 0) {
            help();
        } else {
            printf("try again\n");
        }
    }


    return 0;
}