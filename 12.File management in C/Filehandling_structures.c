#include <stdio.h>

struct invent_record
{
    char name[10];
    int number;
    float price;
    int quantity;
};

void append(struct invent_record *product, FILE *ptr);

int main()
{
    struct invent_record item;
    char filename[20];
    int response;
    FILE *fp;
    long n;

    printf("Type filename: ");
    scanf("%s", filename);

    // Open file for appending and reading
    fp = fopen(filename, "a+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    do
    {
        append(&item, fp);
        printf("\nItem %s appended.\n", item.name);
        printf("Do you want to add another item (1 for YES / 0 for NO)? ");
        scanf("%d", &response);
    } while (response == 1);

    // Get current position (end of file)
    n = ftell(fp);

    fclose(fp);

    // Reopen file to read and display contents
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nContents of %s:\n", filename);
    while (ftell(fp) < n && 
           fscanf(fp, "%s %d %f %d", item.name, &item.number, &item.price, &item.quantity) == 4)
    {
        printf("%-10s %7d %8.2f %8d\n", item.name, item.number, item.price, item.quantity);
    }

    fclose(fp);

    return 0;
}

void append(struct invent_record *product, FILE *ptr)
{
    printf("Item name: ");
    scanf("%s", product->name);
    printf("Item number: ");
    scanf("%d", &product->number);
    printf("Item price: ");
    scanf("%f", &product->price);
    printf("Quantity: ");
    scanf("%d", &product->quantity);

    fprintf(ptr, "%s %d %.2f %d\n",
            product->name,
            product->number,
            product->price,
            product->quantity);
}
