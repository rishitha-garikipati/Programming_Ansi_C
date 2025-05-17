#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int i;
    char word[15];

    if (argc < 3) {
        printf("Usage: %s <filename> <words...>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("Cannot open file %s for writing.\n", argv[1]);
        return 1;
    }

    printf("Number of arguments in command line = %d\n\n", argc);

    // Write all arguments from argv[2] onwards to the file
    for (i = 2; i < argc; i++) {
        fprintf(fp, "%s ", argv[i]);
    }
    fclose(fp);

    printf("Contents of %s file:\n\n", argv[1]);

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Cannot open file %s for reading.\n", argv[1]);
        return 1;
    }

    // Read back the words and print them
    for (i = 2; i < argc; i++) {
        if (fscanf(fp, "%14s", word) == 1) {  // limit to avoid overflow
            printf("%s ", word);
        }
    }
    printf("\n");
    fclose(fp);

    printf("\n");

    // Print the command line arguments with increasing indentation
    for (i = 0; i < argc; i++) {
        printf("%*s\n", i * 5, argv[i]);
    }

    return 0;
}
