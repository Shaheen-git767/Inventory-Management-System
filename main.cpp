// #include<iostream>
// #include<map>
// #include<vector>
// #include<algorithm>
// #include<fstream>
// #include<iomanip>
// #include <sstream>
// using namespace std;
#include "inventory.h"


// struct Product
// {
//     int id;
//     string name;
//     double price;
//     int quantity;
// };

// map<int, Product> inventory;

// void pressEnter()
// {
//     cout << "\n---------------------------------------";
//     cout << "\nPress Enter to return to Main Menu...";
//     cin.ignore();
//     cin.get();
// }

int main()
{

    loadFromFile();

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     INVENTORY MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Stock\n";
        cout << "5. Sell Product\n";
        cout << "6. Delete Product\n";
        cout << "7. Sort Products\n";
        cout << "8. Low Stock Report\n";
        cout << "9. Total Inventory Value\n";
        cout<<"10.exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
            updateStock();
            break;
            case 5:
             sellProduct();
            break;
            case 6:
            deleteProduct();
            break;
            case 7:
            sortProducts();
        break;
            case 8:
            lowStockReport();
            break;
            case 9:
            totalInventoryValue();
            break;
            case 10:
    saveToFile();
    cout << "\nData Saved Successfully.\n";
    cout << "Thank You!\n";
    break;

            default:
                cout << "\nFeature not implemented yet.\n";
        }

if(choice != 10)
{
    pressEnter();
}
    } 
 
    while(choice != 10);
   

    return 0;
}