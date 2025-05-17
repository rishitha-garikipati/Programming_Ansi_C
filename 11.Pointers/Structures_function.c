//STRUCTURES AS FUNCTION PARAMETERS
#include <stdio.h>

struct stores {
    char name[20];
    float price;
    int quantity;
};

void update(struct stores *product, float p, int q);
float mul(struct stores *stock);

int main() {
    float p_increment, value;
    int q_increment;
    static struct stores item = {"XYZ", 25.75, 12};
    struct stores *ptr = &item;

    printf("\nInput increment values:\n");
    printf("Price increment and quantity increment: ");
    scanf("%f %d", &p_increment, &q_increment);

    update(&item, p_increment, q_increment);

    printf("Updated values of item\n\n");
    printf("Name:    %s\n", ptr->name);
    printf("Price:   %.2f\n", ptr->price);
    printf("Quantity: %d\n", ptr->quantity);

    value = mul(&item);
    printf("\nValue of the item = %.2f\n", value);

    return 0;
}

void update(struct stores *product, float p, int q) {
    product->price += p;
    product->quantity += q;
}

float mul(struct stores *stock) {
    return stock->price * stock->quantity;
}
