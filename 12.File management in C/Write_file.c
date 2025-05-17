#include <stdio.h>

int main()
{
    FILE *f1, *f2, *f3;
    int number, i;

    printf("Contents of DATA file\n\n");
    f1 = fopen("DATA", "w");  
    if (f1 == NULL) {
        printf("Error opening DATA file for writing.\n");
        return 1;
    }

    for (i = 1; i <= 30; i++)
    {
        scanf("%d", &number);
        if (number == -1) 
            break;
        putw(number, f1);
    }
    fclose(f1);

    f1 = fopen("DATA", "r");
    if (f1 == NULL) {
        printf("Error opening DATA file for reading.\n");
        return 1;
    }
    f2 = fopen("ODD", "w");
    if (f2 == NULL) {
        printf("Error opening ODD file for writing.\n");
        fclose(f1);
        return 1;
    }
    f3 = fopen("EVEN", "w");
    if (f3 == NULL) {
        printf("Error opening EVEN file for writing.\n");
        fclose(f1);
        fclose(f2);
        return 1;
    }

    while ((number = getw(f1)) != EOF)
    {
        if (number % 2 == 0)
            putw(number, f3);
        else
            putw(number, f2);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f2 = fopen("ODD", "r");
    if (f2 == NULL) {
        printf("Error opening ODD file for reading.\n");
        return 1;
    }
    f3 = fopen("EVEN", "r");
    if (f3 == NULL) {
        printf("Error opening EVEN file for reading.\n");
        fclose(f2);
        return 1;
    }

    printf("\n\nContents of ODD file \n\n");
    while ((number = getw(f2)) != EOF)
        printf("%4d", number);

    printf("\n\nContents of EVEN file \n\n");
    while ((number = getw(f3)) != EOF)
        printf("%4d", number);

    fclose(f2);
    fclose(f3);

    return 0;
}
