#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    FILE *logs = fopen("access_log_Jul95", "r");
    FILE *errList = fopen("500_error.txt", "w");

    char curLog[4096] = "";
    int errorCounter = 0;
    int strCounter = 0;
    int lineCounter = 0;

    int *timeList;
    timeList = (int *) malloc(2000000 * sizeof(int));
    int timeListSize = 2000000;

    while (fgets(curLog, 4096, logs)) {
        lineCounter++;
        if (lineCounter == timeListSize) {
            timeListSize += 2000000;
            timeList = (int *) realloc(timeList, timeListSize * sizeof(int));
        }
        int day = 0, hour = 0, minute = 0, second = 0;
        char s1[4096] = "", s2[4096] = "", s3[4096] = "", s4[4096] = "", error[4096] = "";
        sscanf(curLog, "%*s - - [%d/Jul/1995:%d:%d:%d -0400] %s %s %s %s",
               &day, &hour, &minute, &second, s1, s2, s3, s4);

        int time = (day - 1) * 24 * 60 * 60 + hour * 60 * 60 + minute * 60 + second;
        timeList[strCounter++] = time;

        for (int j = strlen(curLog) - 1; j >= 0; j--) {
            if (curLog[j] == ' ') {
                error[2] = curLog[j - 1];
                error[1] = curLog[j - 2];
                error[0] = curLog[j - 3];
                break;
            }
        }
        if (error[0] == '5') {
            fprintf(errList, "ERROR: %s\t\t", error);
            errorCounter++;
            if (strcmp(error, s4) == 0) {
                fprintf(errList, "REQUEST: %s %s %s\n", s1, s2, s3);
            } else {
                fprintf(errList, "REQUEST: %s %s\n", s1, s2);
            }
        }
    }
    fprintf(errList, "Total number of 5xx errors occurred: %d.", errorCounter);
    int interval = 0;
    printf("Set time interval in seconds:\n");
    scanf("%d", &interval);
    maxRequestInterval(timeList, interval, lineCounter);
    fclose(logs);
    fclose(errList);
    free(timeList);
    return 0;
}
