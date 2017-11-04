//
// Created by Jeremiah on 11/3/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "operations.h"

// insert a node to the list
int insert(product **l, product * node) {
    product * prev;
    product * cursor = l[0];
    if(strcmp(cursor->name,node->name) != 0){
        prev = cursor;
        cursor = cursor->next;
    }
    if(cursor == NULL){
        prev->next = node;
    }
    if(strcmp(cursor->name,node->name) == 0){
        cursor->quantity_value += node->quantity_value;
    }
}

// remove a node from list
void rmItem(product *l, product *node) {
    product *ptr;
    ptr = l;
    if (strcmp(ptr->name, node->name) == 0) {
        l = &node->next;
    }
    while (strcmp(ptr->next->name, node->name) != 0 && ptr->next != NULL) {
        ptr = ptr->next;
    }
    if (strcmp(ptr->next->name, node->name) == 0) {
        ptr->next = NULL;
    } else {
        printf("Product Not Found\n");
    }
}

// show list
void showList(product **l) {
    product *ptr;
    ptr = l[0];
    while (ptr != NULL) {
        printf("%s: %f %s sold at %f %s \n", ptr->name, ptr->quantity_value, ptr->quantity_unit, ptr->price_value,
               ptr->price_unit);
        ptr = ptr->next;
    }
}

// load data from file inf
int loadData(char *filename, product **list) {
    product * Temp = (product *)malloc(sizeof(product));
    FILE *in;
    in = fopen(filename, "r+");
    if (in == NULL) {
        fprintf(stderr, "File Not Found");
        return 1;
    }

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    char *load_data = (char *) malloc(sizeof(char) * size);
    fread(load_data, sizeof(char), size, in);
    const char *delimiter = "|";
    char *data = strtok(load_data, delimiter);
    int i = 0;
    while (data != NULL) {
        strcpy(Temp->name, data);
        data = strtok(NULL, delimiter);
        Temp->quantity_value = (float) atof(data);
        data = strtok(NULL, delimiter);
        strcpy(Temp->quantity_unit, data);
        data = strtok(NULL, delimiter);
        Temp->price_value = (float) atof(data);
        data = strtok(NULL, delimiter);
        strcpy(Temp->price_unit, data);
        Temp->next = NULL;
        data = strtok(NULL, delimiter);
        Temp->next = NULL;
        list[i] = Temp;
        Temp = (product *) malloc(sizeof(product));
        if(i > 0){
            list[i-1]->next = list[i];
        }
        i++;
    }
}

// save data to file outf
int saveData(char *filename, product *ptr) {
    FILE *out = fopen(filename, "w+");
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    char *data;
    while (ptr->next != NULL) {
        char *text = NULL;
        sprintf(text, "%s|%f|%s|%f|%s~", ptr->name, ptr->quantity_unit, ptr->quantity_unit, ptr->price_value,
                ptr->price_unit);
        strcat(data, text);
        ptr = ptr->next;
    }
    fwrite(data, sizeof(char), strlen(data), out);
    fclose(out);
}

// sell product product of quantity q
float purchase(product *l, char p[], float q) {
    product *ptr;
    ptr = l;
    if (strcmp(ptr->name, p) != 0) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
    printf("Product Not Found");
        return 0;
    }
    if(strcmp(ptr->name,p) == 0){
        if(ptr->quantity_value < q){
            q = ptr->quantity_value;
        }
        ptr->quantity_value -= q;
        return q * ptr->price_value;
    }
}

// check out price of product p from list l
void check_price(product *l, char p[]) {
    product *ptr;
    ptr = l;
    while (ptr != NULL) {
        if (strcmp(ptr->name, p) == 0) {
            printf("Name: %s  -  Price: %f %s", ptr->name, ptr->price_value, ptr->price_unit);
            ptr = ptr->next;
        } else {
            ptr = ptr->next;
        }
    }
    if (ptr == NULL) {
        printf("Product Not found");
    }
}

// find a product p from list l
void findItem(product *l, char p[]) {
    product *ptr;
    ptr = l;
    if (strcmp(ptr->name, p) != 0) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        printf("Product Not Found");
    }
    if(strcmp(ptr->name,p) == 0){
        printf("%s: %f %s sold at %f %s \n", ptr->name, ptr->quantity_value, ptr->quantity_unit, ptr->price_value, ptr->price_unit);
    }
}

void openShop(product **l) {
    char *filename = "Inventory.txt";
    loadData(filename, l);
}

void closeShop(product **l) {
    saveData("Inventory.txt", l);
}
