#include "Inventory.h"

map<int, Product> inventory;


void pressEnter()
{
    cout << "\n---------------------------------------";
    cout << "\nPress Enter to return to Main Menu...";
    cin.ignore();
    cin.get();
}
void addProduct()
{
    Product p;

    cout << "Enter Product ID: ";
    cin >> p.id;

    if(inventory.find(p.id) != inventory.end())
    {
        cout << "Product ID already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, p.name);

    cout << "Enter Price: ";
    cin >> p.price;

    cout << "Enter Quantity: ";
    cin >> p.quantity;

    inventory[p.id] = p;
    cout << "\nTotal Products: " << inventory.size() << endl;

    cout << "Product Added Successfully!\n";
}
void displayProducts()
{
    if(inventory.empty())
    {
        cout << "Inventory is Empty.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(15) << "Price"
         << setw(10) << "Quantity"
         << endl;

    cout << "-------------------------------------------------------------\n";

    for(const auto &product : inventory)
    {
        cout << left
             << setw(10) << product.second.id
             << setw(25) << product.second.name
             << setw(15) << product.second.price
             << setw(10) << product.second.quantity
             << endl;
    }
}


bool compareID(const Product &a, const Product &b)
{
    return a.id < b.id;
}

vector<Product> getProductVector()
{
    vector<Product> products;

    for(const auto &product : inventory)
    {
        products.push_back(product.second);
    }

    return products;
}
void searchProduct()
{
    if(inventory.empty())
    {
        cout << "\nInventory is Empty!\n";
        return;
    }
    cout << "\nSearch By";
    cout << "\n1. Product ID";
    cout << "\n2. Product Name";
    cout << "\nEnter Choice: ";

    int choice;
    cin >> choice;
    if(choice==1){
    vector<Product> products = getProductVector();

    sort(products.begin(), products.end(), compareID);

    int id;

    cout << "Enter Product ID to Search: ";
    cin >> id;

    int left = 0;
    int right = products.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(products[mid].id == id)
        {
            cout << "\n========== Product Found ==========\n";

            cout << "ID       : " << products[mid].id << endl;
            cout << "Name     : " << products[mid].name << endl;
            cout << "Price    : " << products[mid].price << endl;
            cout << "Quantity : " << products[mid].quantity << endl;

            return;
        }

        else if(products[mid].id < id)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    cout << "\nProduct Not Found!\n";
}


else if(choice == 2)
{
    cin.ignore();

    string name;

    cout << "\nEnter Product Name: ";
    getline(cin, name);

    bool found = false;

    for(const auto &product : inventory)
    {
        if(product.second.name == name)
        {
            cout << "\n========== Product Found ==========\n";

            cout << "ID       : " << product.second.id << endl;
            cout << "Name     : " << product.second.name << endl;
            cout << "Price    : " << product.second.price << endl;
            cout << "Quantity : " << product.second.quantity << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nProduct Not Found!\n";
    }
}


else
{
    cout << "\nInvalid Choice!\n";
}
}

void updateStock()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    auto it = inventory.find(id);

    if(it != inventory.end())
    {
        cout << "\nCurrent Quantity: "
             << it->second.quantity << endl;

        int addedQuantity;

        cout << "Enter Quantity to Add: ";
        cin >> addedQuantity;
        if(addedQuantity <= 0)
{
    cout << "\nInvalid Quantity!\n";
    return;
}



        it->second.quantity += addedQuantity;

        cout << "\nUpdated Quantity: "
             << it->second.quantity << endl;

        cout << "\nStock Updated Successfully!\n";
    }
    else
    {
        cout << "\nProduct Not Found!\n";
    }
}
void sellProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    auto it = inventory.find(id);

    if(it != inventory.end())
    {
        int sellQuantity;

        cout << "\nCurrent Stock: "
             << it->second.quantity << endl;

        cout << "Enter Quantity to Sell: ";
        cin >> sellQuantity;

        if(sellQuantity <= 0)
        {
            cout << "\nInvalid Quantity!\n";
            return;
        }

        if(sellQuantity > it->second.quantity)
        {
            cout << "\nNot Enough Stock!\n";
            return;
        }

        it->second.quantity -= sellQuantity;

        cout << "\nProduct Sold Successfully!\n";
        cout << "Remaining Stock: "
             << it->second.quantity << endl;
    }
    else
    {
        cout << "\nProduct Not Found!\n";
    }
}
void deleteProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    auto it = inventory.find(id);

    if(it != inventory.end())
    {
        inventory.erase(id);

        cout << "\nProduct Deleted Successfully!\n";
    }
    else
    {
        cout << "\nProduct Not Found!\n";
    }
}


bool compareName(const Product &a, const Product &b)
{
    return a.name < b.name;
}

bool compareQuantity(const Product &a, const Product &b)
{
    return a.quantity < b.quantity;
}

bool comparePrice(const Product &a, const Product &b)
{
    return a.price < b.price;
}





void sortProducts()
{

    if(inventory.empty())
{
    cout<<"\nInventory is Empty!\n";
    return;
}
  vector<Product> products = getProductVector();

    int choice;

    cout << "\n========== SORT PRODUCTS ==========\n";
    cout << "1. Sort by Name\n";
    cout << "2. Sort by Price\n";
    cout << "3. Sort by Quantity\n";

    cout << "\nEnter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            sort(products.begin(), products.end(), compareName);
            break;

        case 2:
            sort(products.begin(), products.end(), comparePrice);
            break;

        case 3:
            sort(products.begin(), products.end(), compareQuantity);
            break;

        default:
            cout << "\nInvalid Choice!\n";
            return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(15) << "Price"
         << setw(10) << "Quantity"
         << endl;

    cout << "-------------------------------------------------------------\n";

    for(const auto &product : products)
    {
        cout << left
             << setw(10) << product.id
             << setw(25) << product.name
             << setw(15) << product.price
             << setw(10) << product.quantity
             << endl;
    }
}



void lowStockReport()
{
    if(inventory.empty())
    {
        cout << "\nInventory is Empty!\n";
        return;
    }
    int threshold;

cout << "Enter Low Stock Threshold: ";
cin >> threshold;

if(threshold <= 0)
{
    cout<<"Invalid Threshold!\n";
    return;
}

    bool found = false;

    cout << "\n========== LOW STOCK REPORT ==========\n\n";

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Quantity"
         << endl;

    cout << "---------------------------------------------\n";

    for(const auto &product : inventory)
    {
        if(product.second.quantity <= threshold)
        {
            found = true;

            cout << left
                 << setw(10) << product.second.id
                 << setw(25) << product.second.name
                 << setw(10) << product.second.quantity
                 << endl;
        }
    }

    if(!found)
    {
        cout << "No Low Stock Products.\n";
    }
}


void totalInventoryValue()
{
    if(inventory.empty())
    {
        cout << "\nInventory is Empty!\n";
        return;
    }

    double totalValue = 0;

    cout << "\n========== INVENTORY VALUE ==========\n\n";

    cout << left
         << setw(25) << "Product"
         << setw(15) << "Value"
         << endl;

    cout << "------------------------------------------\n";
    cout << fixed << setprecision(2);
    for(const auto &product : inventory)
    {
        double value =
            product.second.price * product.second.quantity;

        totalValue += value;

        cout << left
             << setw(25) << product.second.name
             << setw(15) << value
             << endl;
    }

    cout << "------------------------------------------\n";

    cout <<fixed<<setprecision(2)<< "\nTotal Inventory Value = Rs. "
         << totalValue << endl;
}


void saveToFile()
{
    ofstream file("inventory.txt");

    if(!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    for(const auto &product : inventory)
    {
        file << product.second.id << "|"
             << product.second.name << "|"
             << product.second.price << "|"
             << product.second.quantity << endl;
    }

    file.close();
}

void loadFromFile()
{
    ifstream file("inventory.txt");

    if(!file)
    {
        return;
    }

    Product p;
    string line;

    while(getline(file, line))
    {
        // Skip empty lines
        if(line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string id, name, price, quantity;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, price, '|');
        getline(ss, quantity, '|');

        // Skip invalid records
        if(id.empty() || name.empty() || price.empty() || quantity.empty())
        {
            continue;
        }

        p.id = stoi(id);
        p.name = name;
        p.price = stod(price);
        p.quantity = stoi(quantity);

        inventory[p.id] = p;
    }

    file.close();
}
