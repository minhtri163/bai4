#include <stdio.h>
#include <string.h>

enum ProductType {
    CLOTHING,
    FOOTWEAR,
    ELECTRONICS
};

union ProductDetails {
    int size;
    float weight;
};

struct Product {
    char name[50];
    float price;
    enum ProductType type;
    union ProductDetails details;
};

void displayProduct(struct Product product) {
    printf("Name: %s\n", product.name);
    printf("Price: %.2f\n", product.price);
    
    if (product.type == CLOTHING || product.type == FOOTWEAR) {
        printf("Size: %d\n", product.details.size);
    } else if (product.type == ELECTRONICS) {
        printf("Weight: %.2f\n", product.details.weight);
    }
}

int main() {
    int numProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    struct Product products[numProducts];

    for (int i = 0; i < numProducts; i++) {
        printf("\nEnter information for product %d:\n", i + 1);
        printf("Name: ");
        scanf(" %s", &products[i].name);
        printf("Price: ");
        scanf("%f", &products[i].price);
        printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
        int typechoice;
        scanf("%d", &typechoice);
        products[i].type = (enum ProductType)typechoice;

        if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
            printf("Size: ");
            scanf(" %d", &products[i].details.size);
        } else if (products[i].type == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &products[i].details.weight);
        }
    }

    char searchName[50];
    printf("\nEnter the name of the product to retrieve information: ");
    scanf(" %s", &searchName);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, products[i].name) == 0) {
            found = 1;
            printf("\nProduct Information:\n");
            displayProduct(products[i]);
            if(products->type == 0){
                printf("Type: CLOTHING");
            }
            else if(products->type == 1){
                printf("Type: FOOTWEAR");
            }
            else if(products->type == 2){
                printf("Type: ELECTRONICS");
            }
            // break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }

    return 0;
}
