#include <stdio.h>

int main() 
{ 
    char filename[100];  // allocate buffer for filename
    FILE *fp1, *fp2;
    int i, number;

    fp1 = fopen("TEST", "w");
    if(fp1 == NULL) {
        printf("Error opening TEST for writing.\n");
        return 1;
    }
    
    for(i = 10; i <= 100; i += 10)
        putw(i, fp1);

    fclose(fp1);

    printf("\nInput filename:\n");

    // Loop until valid file is opened
    while(1) {
        scanf("%99s", filename);  // limit input size
        fp2 = fopen(filename, "r");
        if(fp2 == NULL) {
            printf("Cannot open the file. Type filename again.\n\n");
        } else {
            break; // file opened successfully
        }
    }
    
    for(i = 1; i <= 20; i++) {
        number = getw(fp2);
        if(feof(fp2)) {
            printf("\nRan out of data.\n");
            break;
        } else {
            printf("%d\n", number);
        }
    } 

    fclose(fp2);
    return 0;
}
