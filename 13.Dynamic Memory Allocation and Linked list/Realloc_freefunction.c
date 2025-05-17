//Use of realloc and free function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer;

    // Allocate memory using malloc
    buffer = (char *)malloc(10 * sizeof(char));
    if (buffer == NULL)
    {
        printf("malloc failed.\n");
        exit(1);
    }

    printf("Buffer of size 10 created.\n");

    // Copy initial string to buffer
    strcpy(buffer, "HYDERABAD");
    printf("\nBuffer contains: %s\n", buffer);

    // Reallocate memory using realloc
    buffer = (char *)realloc(buffer, 15 * sizeof(char));
    if (buffer == NULL)
    {
        printf("Reallocation failed\n");
        exit(1);
    }

    printf("\nBuffer size modified.\n");
    printf("Buffer still contains: %s\n", buffer);

    // Modify buffer contents
    strcpy(buffer, "SECUNDERABAD");
    printf("Buffer now contains: %s\n", buffer);

    // Free memory
    free(buffer);

    return 0;
}
