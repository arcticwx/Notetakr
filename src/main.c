#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// For future: GUI with SDL?

void write(char **towrite[20], char **filename[]){
    FILE *file;
    file = fopen(filename, "w+");
    fputs(towrite, file);
    fclose(file);
}

void read(char **filename){
    FILE *file;
    char buff[255];

    file = fopen(filename, "r");
    fgets(buff, 255, (FILE*)file);
    printf("Contents:   %s\n", buff);
    fclose(file);
}

int main(void){
    printf("Welcome to notetakr, what option?   ");

    char opt[20];
    scanf("%s", opt);

    /* Writing logic */
    if (strcmp(opt, "write") == 0) { 
        printf("Option chose: Written. enter your filename:   ");
        char arg[20];
        char name[20];
        scanf("%s", &name); printf("and the note:   "); scanf("%s", &arg);  write(arg, name);
    }

    /* Reading logic */ // TODO: FIX / COMPLETE
    if(strcmp(opt, "read") == 0){
        printf("Option chose: Read. enter the file to read:   ");
        char name[20];
        scanf("%s", &name);
    }

    return 0;
}