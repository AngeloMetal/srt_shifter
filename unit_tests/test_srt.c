#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../srt_shifter.h"
#include "acutest/acutest.h"

void test_timeToSeconds(){
    char *time = "00:45:30";
    TEST_CHECK(timeToSeconds(time) == 2730);
}

void test_secondsToTime(){
    int seconds = 2730;
    TEST_CHECK(!strcmp(secondsToTime(seconds), "00:45:30"));
}

void test_add_seconds(){
    char *time = malloc(9 * sizeof(char));
    strcpy(time, "00:45:30");
    int seconds = 10;
    add_seconds(time, 10);
    TEST_CHECK(!strcmp(time, "00:45:40"));
}

TEST_LIST = {
        { "test_timeToSeconds", test_timeToSeconds },
        { "test_secondsToTime", test_secondsToTime },
        { "test_add_seconds", test_add_seconds },
        { NULL, NULL } /* zeroed record marking the end of the list */
};