#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int timeToSeconds(char *time){
    int hours, minutes, seconds;
    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
    int total_seconds = seconds + minutes*60 + hours*60*60;
    return total_seconds;
}

// takes total seconds and returns the corresponded time (as buffer time)
char *secondsToTime(char *buffer_time, int total_seconds){
    int seconds = total_seconds;

    // 1 hour = 3600 seconds
    int hours = seconds / 3600;
    seconds -= hours * 3600;

    // 1 minute is 60 seconds
    int minutes = seconds / 60;
    seconds -= minutes * 60;

    sprintf(buffer_time, "%02d:%02d:%02d", hours, minutes, seconds);
    return buffer_time;
}

// takes time and seconds, adds them together, and returns new time
void add_seconds(char *time, int seconds){
    char *buffer = malloc(9 * sizeof(char));
    strcpy(time, secondsToTime(buffer, timeToSeconds(time) + seconds));
    free(buffer);
}

