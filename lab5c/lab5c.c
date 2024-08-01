#include <stdio.h>

typedef struct {
    int hour;
    int min;
    int sec;
} Time;

Time elapsedTime(Time, Time);

int main(){
    Time t1 = {};
    Time t2 = {};
    Time t3 = {};
    Time t4 = {};
    
    printf("What hour is it for the first time? ");
    scanf(" %d", &t1.hour);
    printf("What minute is it for the first time? ");
    scanf(" %d", &t1.min);
    printf("What second is it for the first time? ");
    scanf(" %d", &t1.sec);
    puts("");

    printf("What hour is it for the second time? ");
    scanf(" %d", &t2.hour);
    printf("What minute is it for the second time? ");
    scanf(" %d", &t2.min);
    printf("What second is it for the second time? ");
    scanf(" %d", &t2.sec);
    puts("");

    printf("What hour is it for the third time? ");
    scanf(" %d", &t3.hour);
    printf("What minute is it for the third time? ");
    scanf(" %d", &t3.min);
    printf("What second is it for the third time? ");
    scanf(" %d", &t3.sec);
    puts("");

    printf("What hour is it for the fourth time? ");
    scanf(" %d", &t4.hour);
    printf("What minute is it for the fourth time? ");
    scanf(" %d", &t4.min);
    printf("What second is it for the fourth time? ");
    scanf(" %d", &t4.sec);
    puts("");

    Time diff12 = elapsedTime(t1, t2);
    printf("Time elapsed from the 1st to 2nd time: %d hours, %d minutes, %d seconds\n", diff12.hour, diff12.min, diff12.sec);

    Time diff34 = elapsedTime(t3, t4);
    printf("Time elapsed from the 3rd to 4th time: %d hours, %d minutes, %d seconds\n", diff34.hour, diff34.min, diff34.sec);

    puts("");
}

Time elapsedTime(Time start, Time end){
    int startTotal = start.hour*3600 + start.min*60 + start.sec;
    int endTotal = end.hour*3600 + end.min*60 + end.sec;
    Time retTime = {0, 0, 0};

    // if same time, automatically return 0
    if (endTotal == startTotal){
        return retTime;
    }

    int timeDiff = 0;
    //if start time earlier
    if (endTotal > startTotal){
        timeDiff = endTotal - startTotal;
    }
    //if start time later
    else{
        timeDiff = 24*3600 - (startTotal - endTotal);
    }

    retTime.sec = timeDiff % 60;
    timeDiff /= 60;
    retTime.min = timeDiff % 60;
    timeDiff /= 60;
    retTime.hour = timeDiff;
    return retTime;
}