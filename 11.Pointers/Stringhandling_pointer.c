//String handling by pointers
#include <stdio.h>

int main() {
    char *name;
    int length;
    name = "DELHI";
    char *cptr = name;

    while (*cptr != '\0') {
        printf("%c is stored at address %p\n", *cptr, (void *)cptr);
        cptr++;
    }

    length = cptr - name;
    printf("\nLength of the string: %d\n", length);

    return 0;
}
