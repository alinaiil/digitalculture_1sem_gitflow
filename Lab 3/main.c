#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void maxRequestInterval(const int *timeList, int interval, int size) {
    interval--;
    int left = 0, right = 0;
    int curLeftDate = 0, curRightDate = 0;
    int leftDate = 0, rightDate = 0;
    int maxResult = 0;
    int counter = 0;
	
	for (int i = 0; i < size; i++) {
        while (right < size && timeList[right] - timeList[left] <= interval) {
            counter++;
            if (timeList[right] > 0) {
                curRightDate = right;
            }
            right++;
        }
        if (right == size) {
            if (maxResult < counter) {
                maxResult = counter;
                leftDate = curLeftDate;
                rightDate = curRightDate;
            }
            break;
        } else {
            if (maxResult < counter) {
                maxResult = counter;
                leftDate = curLeftDate;
                rightDate = curRightDate;
            }
            left++;
            counter--;
            curLeftDate = left;
        }
    }

    int secLeft, minLeft, hourLeft, dayLeft;
    secLeft = timeList[leftDate] % 60;
    minLeft = (timeList[leftDate] / 60) % 60;
    hourLeft = ((timeList[leftDate] / 60) / 60) % 24;
    dayLeft = ((timeList[leftDate] / 60) / 60) / 24 + 1;
    int secRight, minRight, hourRight, dayRight;
    secRight = timeList[rightDate] % 60;
    minRight = (timeList[rightDate] / 60) % 60;
    hourRight = ((timeList[rightDate] / 60) / 60) % 24;
    dayRight = ((timeList[rightDate] / 60) / 60) / 24 + 1;

    printf("Max number of requests for given interval equals: %d.\n", maxResult);
    printf("Requests were made from %02d/Jul/1995:%02d:%02d:%02d to %02d/Jul/1995:%02d:%02d:%02d.",
           dayLeft, hourLeft, minLeft, secLeft, dayRight, hourRight, minRight, secRight);
}

int main() {
    
}
