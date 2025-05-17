#include <stdio.h>

int main()
{
    FILE *fp;
    int number, quantity, i;
    float price, value;
    char item[10], filename[20];  // Increased filename size for safety

    printf("Input file name:\n");
    scanf("%19s", filename);

    fp = fopen(filename, "w");  // lowercase "w" for write mode
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Input inventory data\n\n");
    printf("Item name Number Price Quantity\n");

    for(i = 1; i <= 3; i++)
    {
        // Fix format specifiers, use & for variables except item string
        scanf("%9s %d %f %d", item, &number, &price, &quantity);

        // Add newline to fprintf to save each record on a new line
        fprintf(fp, "%s %d %.2f %d\n", item, number, price, quantity);
    }

    fclose(fp);

    printf("\n\n");

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("Item name Number Price Quantity Value\n");

    for(i = 1; i <= 3; i++)
    {
        fscanf(fp, "%9s %d %f %d", item, &number, &price, &quantity);
        value = price * quantity;
        // Added commas in printf arguments, fixed spacing
        printf("%-10s %7d %8.2f %8d %11.2f\n", item, number, price, quantity, value);
    }

    fclose(fp);

    return 0;
}
