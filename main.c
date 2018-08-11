#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

void help(){
    printf("\n cd - change directory");
    printf("\n nd - new directory");
    printf("\n ls - show directory");
    printf("\n help - show commands list");
    printf("\n exit - terminate\n\n");
}




void PrintDir(char *cdir){

    printf("firststate\n");

    DIR *dp = opendir(cdir);
    printf("2\n");
    printf(cdir);
    printf("1\n");
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

    char *tempcd;
    char *temps;
    char temp[30] = "123";
    char *arg;
    bool EM = false;

    gets(temp);
    printf(temp);

    temps = temp;
    printf(temps);
    argv[2] = temps;
    tempcd = argv[2];

    while (!EM) {
        argv[1] = gets(temp);
        //gets(arg);
        if (strcmp(argv[1], "cd") == 0) {
            printf("1123\n");
            argv[2] = gets(temp);
            printf(argv[2]);
            printf("\n");
        } else if (strcmp(argv[1], "ls") == 0) {
            printf("321\n");

            printf(tempcd);

            PrintDir(tempcd);
        } else if (strcmp(argv[1], "exit") == 0) {
            EM = true;
        } else if (strcmp(argv[1], "nd") == 0) {
            argv[2] = gets(temp);
            printf(argv[2]);
            printf("/n");
        } else if (strcmp(argv[1], "help") == 0) {
            help();
        } else {
            printf("try again\n");
        }
    }


    return -1;
}
