
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    char code[20];
    float unit_price;
    int quantity;
    float total_price;
};

float calculate_total_price(float unit_price, int quantity) {
    return unit_price * quantity;
}

int main() {
    struct Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        if (num_products >= MAX_PRODUCTS) {
            printf("Maximum product limit reached.\n");
            break;
        }

        printf("Enter product name: ");
        scanf("%s", products[num_products].name);
        printf("Enter product code: ");
        scanf("%s", products[num_products].code);
        printf("Enter unit price: ");
        scanf("%f", &products[num_products].unit_price);
        printf("Enter quantity: ");
        scanf("%d", &products[num_products].quantity);
        
        products[num_products].total_price = calculate_total_price(products[num_products].unit_price, products[num_products].quantity);
        
        num_products++;

        printf("Do you want to enter another product? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_products; i++) {
        fprintf(file, "Product Name: %s\n", products[i].name);
        fprintf(file, "Product Code: %s\n", products[i].code);
        fprintf(file, "Unit Price: %.2f\n", products[i].unit_price);
        fprintf(file, "Quantity: %d\n", products[i].quantity);
        fprintf(file, "Total Price: %.2f\n", products[i].total_price);
    }

    fclose(file);
    printf("Product information saved to products.txt successfully.\n");

    return 0;
}
