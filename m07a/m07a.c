#include <stdio.h>

int main(){

    //sequential file
    FILE* cfPtr; //pointer to a FILE structure

    if ((cfPtr = fopen("clients.txt", "w")) == NULL){
        //fopen takes a file name and a mode ("w" for write)
        //fopen opens a file and returns an address
        puts("File could not be opened");
    }
    else{
        unsigned int account = 5;
        char name[30] = "Gavin";
        double balance = 3.6;

        //when inputing data, enter eof to end data
        // ctrl + d for mac
        // you can keep putting stuff until the eof indicator (use while(!feof(sditn))) to detect all data before the eof
        //feof reads in eof indicators
        fprintf(cfPtr, "%d, %s, %.2f\n", account, name, balance); 
        //fprintf prints to the address of its first argument (cfPtr)
    }
    fclose(cfPtr); //always close a file (OS will usually close file after program termination but still)

    if ((cfPtr = fopen("clients.txt", "r")) == NULL){ // r for read only
        puts("File could not be opened and read");
    }
    else{
        unsigned int account;
        char name[30];
        double balance;

        fscanf(cfPtr, "%d, %29s, %lf", &account, &name, &balance);
        //scans in from the file to these variables

        fclose(cfPtr);
    }
    rewind(cfPtr); //resets the current 'cursor' position to the beginning of the file
    // cursor position is part of FILE



    //random-access file
    //similar to array, stored in boxes of same size
    //can access any address by bytes
    //just read the slides i dont want to copy this lmao
}