#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int timeToSeconds(char *time){
    int hours, minutes, seconds;
    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
    int total_seconds = seconds + minutes*60 + hours*60*60;
    return total_seconds;
}

char *secondsToTime(int total_seconds){
    int seconds = total_seconds;

    // 1 hour = 3600 seconds
    int hours = seconds / 3600;
    seconds -= hours * 3600;

    // 1 minute is 60 seconds
    int minutes = seconds / 60;
    seconds -= minutes * 60;

    char *time = malloc(9 * sizeof(char));
    sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);
    return time;
}

void add_seconds(char* time, int seconds){
    strcpy(time, secondsToTime(timeToSeconds(time) + seconds));
}

