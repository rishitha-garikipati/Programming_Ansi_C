#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *table;
    int size;

    printf("\nWhat is the size of table? ");
    scanf("%d", &size);  // Fixed: added '&' before size
    printf("\n");

    table = (int *)malloc(size * sizeof(int));
    if (table == NULL)
    {
        printf("No space available \n");
        exit(1);
    }

    printf("\nAddress of the first byte is %p\n", (void*)table);

    printf("\nInput table values:\n");
    for (p = table; p < table + size; p++)
    {
        scanf("%d", p);
    }

    printf("\nValues stored in reverse order:\n");
    for (p = table + size - 1; p >= table; p--)
    {
        printf("%d is stored at address %p\n", *p, (void*)p);
    }

    free(table);  // Free allocated memory
    return 0;
}
