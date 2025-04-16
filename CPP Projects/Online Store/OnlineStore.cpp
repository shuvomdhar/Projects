#include <bits/stdc++.h>
using namespace std;

struct Products
{
    string productName;
    int productPrice;
    int productQuantity;

    // Overloading the < operator for comparison
    bool operator<(const Products &other) const
    {
        return productName < other.productName; // Compare based on product name
    }
};

struct Customers
{
    string customerName;
    map<string, int> orderDetails;
    int orderQuantity;
    time_t orderTime;
};

// Function to display products bought by the customers
void displayCustomer(const vector<Customers> &customerLists) {
    for (const auto& customer : customerLists) {
        cout << customer.customerName << " buys ";
        for (const auto& order : customer.orderDetails) {
            cout << order.first; // Print each order
        }
        cout << " in quantity " << customer.orderQuantity << " at " << ctime(&customer.orderTime);
    }
}

// Function to display products
void displayProducts(const set<Products> &productLists)
{
    cout << "\nProduct List:" << endl;
    cout << "Product Name\t\t\tProduct Quantity\t\t\tProduct Price\n";
    for (auto it : productLists)
    {
        cout << it.productName << "\t\t\t\t" << it.productPrice << "\t\t\t\t\t" << it.productQuantity << endl;
    }
}

class forOwner
{
public:
    // Function to add products
    void addProduct(set<Products> &productsLists)
    {
        int addProductNum;
        cout << "Enter the number of products you want to add: ";
        cin >> addProductNum;
        for (int i = 0; i < addProductNum; i++)
        {
            string pName;
            int pPrice, pQuantity;
            cout << "Enter the product name: ";
            cin.ignore();
            getline(cin, pName);
            cout << "Enter the product price: ";
            cin >> pPrice;
            cout << "Enter the product quantity: ";
            cin >> pQuantity;
            Products newProduct = {pName, pPrice, pQuantity};
            productsLists.insert(newProduct);
        }
    }

    // Function to remove products
    void removeProduct(set<Products> &productsLists)
    {
        int delProduct;
        cout << "How many product do you want to delete? ";
        cin >> delProduct;
        for (int i = 0; i < delProduct; i++)
        {
            string delProductName;
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, delProductName);
            bool productExist = false;
            for (auto it = productsLists.begin(); it != productsLists.end();)
            {
                if (it->productName == delProductName)
                {
                    productsLists.erase(it);
                    productExist = true;
                    break;
                }
                else
                {
                    ++it;
                }
            }
            if (!productExist)
            {
                cout << "Product not found." << endl;
            }
        }
    }
};

class forCustomer
{
public:
    // Function to buy products
    void buyProducts(vector<Customers> &customerLists, set<Products> &productsLists)
    {
        int customerNumber;
        cout << "How many customer want to purchase products from the store? ";
        cin >> customerNumber;

        // Loop for each customer to buy products
        for (int i = 0; i < customerNumber; i++)
        {
            string cName;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, cName);
            cout << "How many products do you want to buy? ";
            int buyProducts;
            cin >> buyProducts;

            // Loop for each product to buy
            for (int i = 0; i < buyProducts; i++)
            {
                string buyProductName;
                cout << "Enter the product name what you want to buy: ";
                cin.ignore();
                getline(cin, buyProductName);
                bool productExist = false;

                // Loop for product existence and buy the product
                for (auto it = productsLists.begin(); it != productsLists.end();)
                {
                    if (it->productName == buyProductName)  // Check if product exists
                    {
                        productExist = true;
                        int buyQuantity;
                        cout << "How many " << buyProductName << " do you want to buy? ";
                        cin >> buyQuantity;
                        if (buyQuantity <= it->productQuantity) // Check if quantity is available
                        {
                            Products updatedProduct = *it;  // Create a copy of the product
                            updatedProduct.productQuantity -= buyQuantity;  // Update the quantity
                            productsLists.erase(it);    // Remove the old product
                            productsLists.insert(updatedProduct);   // Insert the updated product
                            Customers newCustomer;
                            newCustomer.customerName = cName;
                            newCustomer.orderDetails[buyProductName] = it->productPrice;
                            newCustomer.orderQuantity = buyQuantity; // If you want to track quantity
                            newCustomer.orderTime = time(0);    // Set current time
                            customerLists.push_back(newCustomer);
                        }
                        else
                        {
                            cout << "Store does not have sufficient quantity of " << buyProductName << endl;
                        }
                        break;
                    }
                    else
                    {
                        ++it;
                    }
                }
                if (!productExist)
                {
                    cout << "Product not found." << endl;
                }
            }
        }
    }
};

int main()
{
    set<Products> productLists = {{"TV", 25000, 17}, {"Fridge", 20000, 10}, {"Laptop", 50000, 15}}; // Products which are already available in the store
    displayProducts(productLists);

    // Checking for owner or customer
    cout << "\nAre you store owner or customer?\nPress '1' if you are store owner\nPress '2' if you are customer\n";
    int choice1;
    cout << "Enter your choice: ";
    cin >> choice1;

    if (choice1 == 1) // Condition to check if user is store owner
    {
        cout << "\nAs an owner you can add and remove product from your store"
             << endl;
        int choice2;
        cout << "Press '1' to add product\nPress '2' to remove product\n";
        cout << "Enter your choice: ";
        cin >> choice2;

        forOwner fo; // Object of class forOwner

        if (choice2 == 1) // Condition to check if user wants to add product
        {
            fo.addProduct(productLists);
            displayProducts(productLists);
        }
        else
        {
            fo.removeProduct(productLists);
            displayProducts(productLists);
        }
    }

    else if (choice1 == 2) // Condition to check if user is customer
    {
        forCustomer fc;
        vector<Customers> customerLists;
        cout << "\nAs a customer you can search and purchase products from the store\n";
        cout << "Available products in the store are:-\n";
        displayProducts(productLists);
        fc.buyProducts(customerLists, productLists);
        displayCustomer(customerLists);
        displayProducts(productLists);
    }

    return 0;
}
