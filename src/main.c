#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void write(char towrite[20], char filename[]){
    FILE *file;
    file = fopen(filename, "w+");
    fputs(towrite, file);
    fclose(file);
}

void read(char *filename){
    FILE *file;
    char buff;
    int n;

    file = fopen(filename, "r");
    if (file == NULL){
        printf("Cannot open file \n");
    }
    printf("Contents:   \n");
    //fgets(buff, 255, file);
    // buff = fgetc(file);
    while((n = fgetc(file)) != EOF){
        // printf("%s\n", buff);
        putchar(n);
    }
    fclose(file);
}

int main(void){
    printf("Welcome to notetakr, what option?   ");

    char opt[20];
    scanf("%s", opt); fflush(stdin);

    /* Writing logic */
    if (strcmp(opt, "write") == 0) { 
        printf("Option chose: \"Write\". enter your filename:   ");
        char arg[255];
        char name[255];
        scanf("%s", &name); fflush(stdin); // bodge
        printf("and the note:   "); 
        fgets(arg, 255, stdin);  
        write(arg, name);
    }

    /* Reading logic */ // TODO: FIX / COMPLETE
    if(strcmp(opt, "read") == 0){
        printf("Option chosen: Read. enter the file to read:   ");
        char *name;
        fgets(name, 255, stdin);
        read(name);
    }

    else if(strcmp(opt, "exit") == 0){
        exit(0);
    }

    return 0;
}