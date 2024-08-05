#include <stdio.h>

typedef struct {
    unsigned int record;
    char toolName[20];
    unsigned int quantity;
    double cost;
} Tool;

int main() {
    FILE* cfPtr;

    // 100 empty records
    if ((cfPtr = fopen("hardware.dat", "wb")) == NULL){
        puts("Couldn't open the file");
    }
    else{
        Tool blankRecord = {0, "", 0, 0.0};
        for (int i=0; i<100; i++){
            blankRecord.record = i + 1;
            fwrite(&blankRecord, sizeof(Tool), 1, cfPtr);
        }
        fclose(cfPtr);
    }

    if ((cfPtr = fopen("hardware.dat", "rb+")) == NULL){
        puts("Couldn't open the file x2");
    }
    else{
        //step 1
        Tool toolRecord = {0, "", 0, 0.0};
        puts("\nPart 1:");
        puts("----------");
        printf("Enter a record # (enter 0 to stop): ");
        scanf("%d", &toolRecord.record);
        while (toolRecord.record != 0){
            printf("Enter the tool's name, quantity, and cost: ");
            fscanf(stdin, " %s %d $%lf", toolRecord.toolName, &toolRecord.quantity, &toolRecord.cost);
            // printf("%s\n", toolRecord.toolName);
            // printf("%d\n", toolRecord.quantity);
            // printf("%f\n", toolRecord.cost);
            fseek(cfPtr, (toolRecord.record - 1)*sizeof(Tool), SEEK_SET);
            fwrite(&toolRecord, sizeof(Tool), 1, cfPtr);
            printf("\nEnter another record #: ");
            scanf(" %d", &toolRecord.record);
        }
         
        //step 2
        puts("\nPart 2:");
        puts("----------");
        Tool delToolRecord= {0, "", 0, 0.0};
        int delRecord;
        printf("Enter a record # to delete: ");
        scanf("%d", &delRecord);
        fseek(cfPtr, (delRecord - 1)*sizeof(Tool), SEEK_SET);
        fwrite(&delToolRecord, sizeof(Tool), 1, cfPtr);

        //step 3
        puts("\nPart 3:");
        puts("----------");
        printf("Please add a new record and enter the record #: ");
        scanf("%d", &toolRecord.record);
        printf("Enter the tool's name, quantity, and cost: ");
        fscanf(stdin, " %s %d $%lf", toolRecord.toolName, &toolRecord.quantity, &toolRecord.cost);
        fseek(cfPtr, (toolRecord.record - 1)*sizeof(Tool), SEEK_SET);
        fwrite(&toolRecord, sizeof(Tool), 1, cfPtr);

        //step 4
        puts("\nPart 4:");
        puts("----------");
        puts("Current file content");
        fseek(cfPtr, 0, SEEK_SET);
        while (!feof(cfPtr)){
            int result = fread(&toolRecord, sizeof(Tool), 1, cfPtr);
            if (result > 0 && toolRecord.record <= 100 && toolRecord.quantity != 0){
                printf("record #%.3d, %6s, %.2d each, $%.2f\n", toolRecord.record, toolRecord.toolName, toolRecord.quantity, toolRecord.cost);
            }
        }
        puts("");

        fclose(cfPtr);
    }

}