//FUNCTIONS WITH ARGUMENTS AND RETURN VALUES 
#include <stdio.h>

// Function Prototypes
void printline(char ch, int len);
float value(float p, float r, int n);

int main() {
    float principal, inrate, amount;
    int period;

    printf("Enter principal amount, interest rate, and period:\n"); 
    scanf("%f %f %d", &principal, &inrate, &period);

    printline('*', 52);

    amount = value(principal, inrate, period); 

    printf("\nPrincipal: %.2f\tRate: %.2f\tPeriod: %d\tAmount: %.2f\n\n", 
           principal, inrate, period, amount);

    printline('=', 52);

    return 0;
}

// Function to print a line of repeated characters
void printline(char ch, int len) {
    for (int i = 1; i <= len; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

// Function to calculate compound interest
float value(float p, float r, int n) {
    float sum = p;
    for (int year = 1; year <= n; year++) {
        sum = sum * (1 + r);
    }
    return sum;
}
