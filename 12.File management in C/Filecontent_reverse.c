#include <stdio.h>

int main() {
    FILE *fp;
    long n;
    char c;

    // Open file for writing
    fp = fopen("RANDOM", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter text (Ctrl+D or Ctrl+Z to end):\n");
    while ((c = getchar()) != EOF)
        putc(c, fp);

    // Get number of characters entered so far
    long chars_entered = ftell(fp);
    printf("No. of characters entered = %ld\n", chars_entered);

    fclose(fp);

    // Open file for reading
    fp = fopen("RANDOM", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    // Example: print character at position n and current position
    n = 0L;
    while (n < chars_entered) {
        fseek(fp, n, SEEK_SET);
        c = getc(fp);
        printf("Character at position %ld is '%c'\n", n, c);
        n += 5L;
    }

    // Print file contents in reverse order
    printf("\nFile contents in reverse order:\n");
    // Move to last character (one before EOF)
    if (fseek(fp, -1L, SEEK_END) == 0) {
        long pos = ftell(fp);
        while (pos >= 0) {
            c = getc(fp);
            putchar(c);
            if (pos == 0) break;  // Reached start of file
            // Move two positions back: one for current char, one more to move backwards
            if (fseek(fp, -2L, SEEK_CUR) != 0) break;
            pos = ftell(fp);
        }
    }
    putchar('\n');

    fclose(fp);
    return 0;
}
