#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"


int main() {
    product **Inventory = (product **) malloc(sizeof(product *)* N);
    product head;
    strcpy(head.name,"head");
    head.next = NULL;
    Inventory[0] = &head;
    openShop(Inventory);
    int i = 0;
    float total = 0;

    printf("Welecome to ALDI\n");
    printf("Please let me know what you want to do according to the menu below:    \n");
    printf("=======================================================================\n");
    printf("| 1: Add product to store              2: Purchase product from store |\n");
    printf("| 3: Check Price of a product          4: show products in store      |\n");
    printf("| 5: Remove product from store         6: Find product                |\n");
    printf("| 7: Show Inventory                    8: Close store for the day     |\n");
    printf("=======================================================================\n");

    while (i != 8) {
        printf("What do you want to do?");
        scanf("%d", &i);

        if (i == 1) {
            product  * node = (product *) malloc(sizeof(product));
            char text[25];
            float num;
            printf("Product Name:");
            scanf("%s", node->name);

            printf("How many %s will be added:", node->name);
            scanf("%f", &node->quantity_value);

            printf("What is one unit of %s called:", node->name);
            scanf("%s", node->quantity_unit);

            printf("What is the price of %s:", node->name);
            scanf("%f", &node->price_value);

            printf("What is the price unit of %s called:", node->name);
            scanf("%s", node->price_unit);

            node->next = NULL;

            insert(Inventory, node);
            i == 0;
        }
        if (i == 2) {
            char text[N];
            printf("What product would you like to buy\n");
            scanf("%s",&text);
            total += purchase(Inventory,text,total);

        }
        if (i == 3) {
            char text[N];
            printf("What product would you like to price check\n");
            scanf("%s",text);
            check_price(Inventory,text);
        }
        if (i == 4) {
            printf("                            Product List                               \n");
            printf("_______________________________________________________________________\n");
            showList(Inventory);
        }
        if (i == 5) {
            product node;
            printf("What product would you like to remove\n");
            scanf("%s",node.name);
            rmItem(Inventory,&node);
        }
        if (i == 6) {
            char text[N];
            printf("What product are you looking for\n");
            scanf("%s",text);
            findItem(Inventory,text);
        }
        if (i == 7) {
            printf("                          ALDI's Inventory                             \n");
            printf("Today's Total: %f\n",total);
            printf("_______________________________________________________________________\n");
            showList(Inventory);
        }
        if (i == 8) {
            closeShop(Inventory);
            printf("ALDI's is now closed");
        }
    }
}