#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srt_shifter.h"

int main(int argc, char **argv){
    FILE *file = fopen(argv[1], "r");
    if(argc < 3){
        printf("Error: you also need to include seconds as argument\n(e.g.: ./srt sub.srt 7 > new_sub.srt)\n");
        return 1;
    }
    if(file == NULL){
        printf("Error: could not open file\n");
        return 2;
    }

    int seconds = atoi(argv[2]);

    char buffer[100];
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        int hh, mm, ss;
        char *temp = malloc(9 * sizeof(char));
        if(sscanf(buffer, "%2d:%2d:%2d", &hh, &mm, &ss) == 3){
            // time before '-->'
            strncpy(temp, buffer, 8);
            add_seconds(temp, seconds);
            strncpy(buffer, temp, 8);

            // time after '-->'
            strncpy(temp, buffer+17, 8);
            add_seconds(temp, seconds);
            strncpy(buffer+17, temp, 8);
        }
        printf("%s", buffer);
        free(temp);    
    }
    
    fclose(file);
    return 0;
}