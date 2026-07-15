#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<cctype>

using namespace std;

struct Product
{
    int id;
    string name;
    double price;
    int quantity;
};

extern map<int, Product> inventory;

// Function Declarations

void pressEnter();
void addProduct();
void displayProducts();
void searchProduct();
void updateStock();
void sellProduct();
void deleteProduct();
void sortProducts();
void lowStockReport();
void totalInventoryValue();
void saveToFile();
void loadFromFile();

bool compareID(const Product &a, const Product &b);
bool compareName(const Product &a, const Product &b);
bool comparePrice(const Product &a, const Product &b);
bool compareQuantity(const Product &a, const Product &b);

vector<Product> getProductVector();

#endif