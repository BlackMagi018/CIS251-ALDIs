//
// Created by Jeremiah on 11/3/2017.
//

#ifndef ALDIS_OPERATIONS_H
#define ALDIS_OPERATIONS_H
#define N 20
struct product
{
    char name[N];
    float quantity_value;
    char quantity_unit[N];
    float price_value;
    char price_unit[N];
    struct product *next;
};
typedef struct product product;

// insert a node to the list
int insert(product **l, product * node);
// remove a node from list
void rmItem(product **l, product *node);
// show list
void showList(product ** l);
// load data from file inf
int loadData(char inf[], product **l);
// save data to file outf
int saveData(char outf[], product **ptr);
// sell product product of quantity q
float purchase(product **l, char product[], float q);
// check out price of product p from list l
void check_price(product **l, char p[]);
// find a product p from list l
void findItem(product **l, char p[]);

void openShop(product **l);

void closeShop(product **l);

#endif //ALDIS_OPERATIONS_H
