// Smaller Super Shop

#include <bits/stdc++.h>
#include <typeinfo>
#include<cstring>
#include <fstream>
#include <utility>
using namespace std;

//Declarations-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Multiplan;
vector<pair<string, int>> purchased_items;
vector<pair<string, int>> wishlisted_items;
vector<Multiplan*> products;
vector<pair<string, string>> users;

//Parent Class Definition-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


class Multiplan
{
    string id;
    string name;
    double price;

public:
    Multiplan(const string &id,const string &name,double price):id(id),name(name),price(price) {}
    string getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
    void setID(const string& id)
    {
        this->id = id;
    }
    void setName(const string& name)
    {
        this->name = name;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    virtual ~Multiplan() {}
};

//PC Parts Sub-Class of Multiplan--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class pc_parts : public Multiplan
{
public:
    pc_parts(const string &id,const string &name,double price): Multiplan(id,name, price) {}
};

//RAM Sub-Class of PC Parts-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class ram : public pc_parts
{
public:
    ram(const string &id,const string &name, double price):pc_parts(id,name,price) {}
};

//CPU Sub-Class of PC Parts-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class cpu : public pc_parts
{
public:
    cpu(const string &id,const string &name, double price):pc_parts(id,name,price) {}
};

//GPU Sub-Class of PC Parts-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class gpu : public pc_parts
{
public:
    gpu(const string &id,const string &name, double price):pc_parts(id,name,price) {}

};

//Laptop Sub-Class of Multiplan---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class laptop : public Multiplan
{
public:
    laptop(const string &id,const string &name,double price): Multiplan(id,name, price) {}
};

//Accessories Sub-Class of Multiplan-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class accessory : public Multiplan
{
public:
    accessory(const string &id,const string &name,double price): Multiplan(id,name, price) {}
};

//Keyboard Sub-Class of Accessories---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class keyboard : public accessory
{
public:
    keyboard(const string &id,const string &name,double price): accessory(id,name, price) {}
};

//Mouse Sub-Class of Accessories-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class mouse : public accessory
{
public:
    mouse(const string &id,const string &name,double price): accessory(id,name, price) {}
};

//Template Function to Allocate Memory for any Class Object taking id, name and price as parameters
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
T* crtObj(string id, string s, double d)
{
    T* obj = new T(id,s,d);
    products.push_back(obj);
    return obj;
}

//Function to Initialize Products via user input----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void add_product()
{
    cout<<"How many products do you want to add? : ";
    int n,m,o;
    string id,s;
    double d;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        cout<<"\nWhat kind of product?\n1.PC component\n2.Laptop\n3.Accessory\n";
        cin>>m;
        cin.ignore();
        if(m==1)
        {
            cout<<"What component?\n1.RAM\n2.CPU\n3.GPU\n";
            cin>>o;
            cin.ignore();
            if(o==1)
            {
                cout<<"Enter product ID :";
                cin>>id;
                cout<<"Enter product name :";
                cin.ignore();
                getline(cin,s);
                cout<<"Enter product price :";
                cin>>d;
                ram *obj = crtObj<ram>(id,s,d);
            }
            else if(o==2)
            {
                cout<<"Enter product ID :";
                cin>>id;
                cout<<"Enter product name :";
                cin.ignore();
                getline(cin,s);
                cout<<"Enter product price :";
                cin>>d;
                cpu *obj = crtObj<cpu>(id,s,d);
            }
            else if(o==3)
            {
                cout<<"Enter product ID :";
                cin>>id;
                cout<<"Enter product name :";
                cin.ignore();
                getline(cin,s);
                cout<<"Enter product price :";
                cin>>d;
                gpu *obj = crtObj<gpu>(id,s,d);
            }
        }
        else if(m==2)
        {
            cout<<"Enter product ID :";
            cin>>id;
            cout<<"Enter product name :";
            cin.ignore();
            getline(cin,s);
            cout<<"Enter product price :";
            cin>>d;
            laptop *obj = crtObj<laptop>(id,s,d);
        }
        else if(m==3)
        {
            cout<<"What accessoruy?\n1.Keyboard\n2.Mouse\n";
            cin>>o;
            cin.ignore();
            if(o==1)
            {
                cout<<"Enter product ID :";
                cin>>id;
                cout<<"Enter product name :";
                cin.ignore();
                getline(cin,s);
                cout<<"Enter product price :";
                cin>>d;
                keyboard obj = *crtObj<keyboard>(id,s,d);
            }
            else if(o==2)
            {
                cout<<"Enter product ID :";
                cin>>id;
                cout<<"Enter product name :";
                cin.ignore();
                getline(cin,s);
                cout<<"Enter product price :";
                cin>>d;
                mouse obj = *crtObj<mouse>(id,s,d);
            }
        }
    }
}

//Function to Display Products available from the products vector---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void display_products()
{
    for (const auto& product : products)
    {
        if(dynamic_cast<ram*>(product))
        {
            cout << "Product: RAM, ";
        }
        else if(dynamic_cast<cpu*>(product))
        {
            cout << "Product: CPU, ";
        }
        else if(dynamic_cast<gpu*>(product))
        {
            cout << "Product: GPU, ";
        }
        else if(dynamic_cast<laptop*>(product))
        {
            cout << "Product: Laptop, ";
        }
        else if(dynamic_cast<keyboard*>(product))
        {
            cout << "Product: Keyboard, ";
        }
        else if(dynamic_cast<mouse*>(product))
        {
            cout << "Product: Mouse, ";
        }
        else
        {
            cout << "Product: Unknown, ";
        }
        cout << "ID :" << product->getID() << ", Name: " << product->getName() << ", Price: " << product->getPrice() << endl;
    }
}

//Function to Clear Objects at the end-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void clear_products()
{
    for (auto& product : products)
    {
        delete product;
    }
    products.clear();
}

//Function to Save Products in a Text Document---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void save_to_file(const string& filename)
{
    ofstream outfile(filename);
    if (!outfile.is_open())
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& product : products)
    {
        if (dynamic_cast<ram*>(product))
        {
            outfile << "ram,";
        }
        else if (dynamic_cast<cpu*>(product))
        {
            outfile << "cpu,";
        }
        else if (dynamic_cast<gpu*>(product))
        {
            outfile << "gpu,";
        }
        else if (dynamic_cast<laptop*>(product))
        {
            outfile << "laptop,";
        }
        else if (dynamic_cast<keyboard*>(product))
        {
            outfile << "keyboard,";
        }
        else if (dynamic_cast<mouse*>(product))
        {
            outfile << "mouse,";
        }
        else
        {
            outfile << "unknown,";
        }
        outfile << product->getID() << "," << product->getName() << "," << product->getPrice() << endl;
    }

    outfile.close();
    cout << "Product information saved to " << filename << endl;
}

//Function to read Products from File--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void read_from_file(const string& filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    string type, id, name;
    double price;
    string line;
    while (getline(infile,line))
    {
        stringstream ss(line);
        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        ss >> price;
        if (type == "ram")
        {
            ram* obj = crtObj<ram>(id,name, price);
        }
        else if (type == "cpu")
        {
            cpu* obj = crtObj<cpu>(id,name, price);
        }
        else if (type == "gpu")
        {
            gpu* obj = crtObj<gpu>(id,name, price);
        }
        else if (type == "laptop")
        {
            laptop* obj = crtObj<laptop>(id,name, price);
        }
        else if (type == "keyboard")
        {
            keyboard* obj = crtObj<keyboard>(id,name, price);
        }
        else if (type == "mouse")
        {
            mouse* obj = crtObj<mouse>(id,name, price);
        }
    }

    infile.close();
    cout << "Product information loaded from " << filename << endl;
}

//Function to Modify an Existing Product--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void edit_product()
{
    cout << "Enter the product ID to edit or delete: ";
    string id;
    cin >> id;

    Multiplan* product_to_edit = nullptr;
    for (auto& product : products)
    {
        if (product->getID() == id)
        {
            product_to_edit = product;
            break;
        }
    }

    if (product_to_edit == nullptr)
    {
        cout << "Product not found." << endl;
        return;
    }

    cout << "What do you want to do?\n1. Edit product\n2. Delete product\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "What do you want to edit?\n1. ID\n2. Name\n3. Price\n";
        int edit_choice;
        cin >> edit_choice;
        cin.ignore();

        if (edit_choice == 1)
        {
            cout << "Enter new ID: ";
            string new_id;
            cin >> new_id;
            product_to_edit->setID(new_id);
        }
        else if (edit_choice == 2)
        {
            cout << "Enter new name: ";
            string new_name;
            cin.ignore();
            getline(cin, new_name);
            product_to_edit->setName(new_name);
        }
        else if (edit_choice == 3)
        {
            cout << "Enter new price: ";
            double new_price;
            cin >> new_price;
            product_to_edit->setPrice(new_price);
        }

        cout << "Product updated successfully." << endl;
    }
    else if (choice == 2)
    {
        auto it = find(products.begin(), products.end(), product_to_edit);
        if (it != products.end())
        {
            products.erase(it);
            cout << "Product deleted successfully." << endl;
        }
    }
}

//Function to Buy product based on ID------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<pair<string, int>> buy_product()
{
    string  product_id;
    int product_quantity;
    cout<<"Enter product ID to buy :";
    cin>>product_id;
    cout<<"Enter quantity :";
    cin>>product_quantity;
    bool found = false;
    for (const auto& product : products)
    {
        if (product->getID() == product_id)
        {
            purchased_items.push_back(make_pair(product_id, product_quantity));
            cout << product->getID() << " : "<< product_quantity << " Product(s) added to cart" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Product with ID " << product_id << " not found." << endl;
    }
    return purchased_items;
}

//Function to Wishlist products based on ID-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<pair<string, int>> wishlist_product()
{
    string  product_id;
    int product_quantity;
    cout<<"Enter product ID to add to wishlist :";
    cin>>product_id;
    cout<<"Enter quantity to add to wishlist :";
    cin>>product_quantity;
    bool found = false;
    for (const auto& product : products)
    {
        if (product->getID() == product_id)
        {
            wishlisted_items.push_back(make_pair(product_id, product_quantity));
            cout << product->getID() << " : "<< product_quantity << " Product(s) added to cart" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Product with ID " << product_id << " not found." << endl;
    }
    return wishlisted_items;
}

//Save Wishlist to File based on Username--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void saveWishlist(const string& username, const vector<pair<string, int>>& newWishlist)
{
    ifstream infile("wishlist.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool skip = false;
    vector<pair<string, int>> existingWishlist;

    while (getline(infile, line))
    {
        if (line == username)
        {
            skip = true;
            while (getline(infile, line) && line != "END")
            {
                string product_id;
                int product_quantity;
                istringstream iss(line);
                iss >> product_id >> product_quantity;
                existingWishlist.push_back(make_pair(product_id, product_quantity));
            }
        }
        else if (line == "END")
        {
            skip = false;
        }

        if (!skip)
        {
            tempFile << line << endl;
        }
    }

    infile.close();

    for (const auto& newItem : newWishlist)
    {
        bool found = false;
        for (const auto& existingItem : existingWishlist)
        {
            if (existingItem.first == newItem.first)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            existingWishlist.push_back(newItem);
        }
    }

    tempFile << username << endl;
    for (const auto& item : existingWishlist)
    {
        tempFile << item.first << " " << item.second << endl;
    }
    tempFile << "END" << endl;

    tempFile.close();

    remove("wishlist.txt");
    rename("temp.txt", "wishlist.txt");
}

//Function to Display Wishlist based on Username---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void displayWishlist(const string& username)
{
    ifstream file("wishlist.txt");
    string line;
    bool userFound = false;
    bool itemsFound = false;

    while (getline(file, line))
    {
        if (line == username)
        {
            userFound = true;
            cout << "Wishlist for " << username << ":" << endl;
            while (getline(file, line) && line != "END")
            {
                string product_id;
                int product_quantity;
                istringstream iss(line);
                iss >> product_id >> product_quantity;
                for (const auto& product : products)
                {
                    if (product->getID() == product_id)
                    {
                        if(dynamic_cast<ram*>(product))
                        {
                            cout << "Product: RAM, ";
                        }
                        else if(dynamic_cast<cpu*>(product))
                        {
                            cout << "Product: CPU, ";
                        }
                        else if(dynamic_cast<gpu*>(product))
                        {
                            cout << "Product: GPU, ";
                        }
                        else if(dynamic_cast<laptop*>(product))
                        {
                            cout << "Product: Laptop, ";
                        }
                        else if(dynamic_cast<keyboard*>(product))
                        {
                            cout << "Product: Keyboard, ";
                        }
                        else if(dynamic_cast<mouse*>(product))
                        {
                            cout << "Product: Mouse, ";
                        }
                        else
                        {
                            cout << "Product: Unknown, ";
                        }

                        cout << "Product Name: " << product->getName() << " (Quantity: " << product_quantity << ")" << endl;
                        cout << "Price per unit: " << product->getPrice() << endl;
                        cout << "Total price: " << product->getPrice() * product_quantity << endl;
                        cout << "--------------------------" << endl;
                        break;
                    }
                }
                itemsFound = true;
            }
            break;
        }
    }

    if (!userFound)
    {
        cout << "No wishlist found for user " << username << "." << endl;
    }
    else if (!itemsFound)
    {
        cout << "No items wishlisted." << endl;
    }

    file.close();
}

//Function to view Bill for Products Bought--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void view_bill(const vector<pair<string, int>>& purchased_items)
{
    cout << "Bill Details:" << endl;
    for (const auto& item : purchased_items)
    {
        const string& product_id = item.first;
        int quantity = item.second;

        for (const auto& product : products)
        {
            if (product->getID() == product_id)
            {
                if(dynamic_cast<ram*>(product))
                {
                    cout << "Product: RAM, ";
                }
                else if(dynamic_cast<cpu*>(product))
                {
                    cout << "Product: CPU, ";
                }
                else if(dynamic_cast<gpu*>(product))
                {
                    cout << "Product: GPU, ";
                }
                else if(dynamic_cast<laptop*>(product))
                {
                    cout << "Product: Laptop, ";
                }
                else if(dynamic_cast<keyboard*>(product))
                {
                    cout << "Product: Keyboard, ";
                }
                else if(dynamic_cast<mouse*>(product))
                {
                    cout << "Product: Mouse, ";
                }
                else
                {
                    cout << "Product: Unknown, ";
                }

                cout << "Product Name: " << product->getName() << " (Quantity: " << quantity << ")" << endl;
                cout << "Price per unit: " << product->getPrice() << endl;
                cout << "Total price: " << product->getPrice() * quantity << endl;
                cout << "--------------------------" << endl;
                break;
            }
        }
    }
}

//Function to Print Bill of Bought Products in a File--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void print_bill(const vector<pair<string, int>>& purchased_items)
{
    double total_price = 0.0;
    ofstream bill_file("bill.txt");
    if (!bill_file.is_open())
    {
        cout << "Error opening bill file for writing." << endl;
        return;
    }

    for (const auto& item : purchased_items)
    {
        const string& product_id = item.first;
        int quantity = item.second;

        for (const auto& product : products)
        {
            if (product->getID() == product_id)
            {
                if(dynamic_cast<ram*>(product))
                {
                    bill_file << "Product: RAM, ";
                }
                else if(dynamic_cast<cpu*>(product))
                {
                    bill_file << "Product: CPU, ";
                }
                else if(dynamic_cast<gpu*>(product))
                {
                    bill_file << "Product: GPU, ";
                }
                else if(dynamic_cast<laptop*>(product))
                {
                    bill_file << "Product: Laptop, ";
                }
                else if(dynamic_cast<keyboard*>(product))
                {
                    bill_file << "Product: Keyboard, ";
                }
                else if(dynamic_cast<mouse*>(product))
                {
                    bill_file << "Product: Mouse, ";
                }
                else
                {
                    bill_file << "Product: Unknown, ";
                }

                double item_price = product->getPrice() * quantity;
                total_price += item_price;
                bill_file << "Product Name: " << product->getName() << " (Quantity: " << quantity << ")" << endl;
                bill_file << "Price per unit: " << product->getPrice() << endl;
                bill_file << "Total price: " << item_price << endl;
                bill_file << "--------------------------" << endl;
                break;
            }
        }
    }

    bill_file << "Total Bill Amount: " << total_price << endl;
    bill_file.close();
    cout << "Bill saved to bill.txt" << endl;
}

//Function to Load Users from File----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loadUsers()
{
    ifstream file("users.txt");
    string name, password;
    while (file >> name >> password)
    {
        users.push_back(make_pair(name, password));
    }
    file.close();
}

//Function to Save Users to File---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void saveUsers()
{
    ofstream file("users.txt");
    for (const auto& user : users)
    {
        file << user.first << " " << user.second << endl;
    }
    file.close();
}

//Function to Add a New User-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void signUp(string& loggedInUser)
{
    string name, password;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;
    users.push_back(make_pair(name, password));
    saveUsers();
    loggedInUser = name;
    cout <<endl<< "Sign up successful!" << endl;
}

//Function to Login using Existing User-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool login(string& loggedInUser)
{
    string name, password;
    cout << "Enter your name: ";
    cin >> name;
    for (const auto& user : users)
    {
        if (user.first == name)
        {
            cout << "Enter your password: ";
            cin >> password;
            if (user.second == password)
            {
                loggedInUser = name;
                cout <<endl<< "Login successful!" << endl;
                return true;
            }
            else
            {
                cout <<endl<< "Incorrect password!" << endl;
                return false;
            }
        }
    }
    cout << "User not found!" << endl;
    return false;
}

//Main Function----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    cout<<"Welcome to Super Tech Shop"<<endl<<endl;
    read_from_file("prod.txt");
    loadUsers();
    string loggedInUser;
B:
    int choice;
    cout << "1. Login\n2. Sign Up\nEnter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        login(loggedInUser);
    }
    else if (choice == 2)
    {
        signUp(loggedInUser);
    }
    else
    {
        cout << "Invalid choice!" << endl;
        goto B;
    }

A:
    cout<<endl;
    cout<<"What do you want to do ?"<<endl<<endl;
    cout<<"1.Add Product\n2.Edit Product\n3.Save Products to File\n4.Display Products\n5.Buy Products\n6.View Bill\n7.Print Bill\n8.Add to Wishlist\n9.View Wishlist\n10.Exit\n\nEnter your choice : ";
    int i;
    cin>>i;
    cout<<endl;
    switch(i)
    {
    case 1:
        add_product();
        break;
    case 2:
        edit_product();
        break;
    case 3:
        save_to_file("prod.txt");
        break;
    case 4:
        display_products();
        break;
    case 5:
        purchased_items=buy_product();
        break;
    case 6:
        view_bill(purchased_items);
        break;
    case 7:
        print_bill(purchased_items);
        break;
    case 8:
        wishlisted_items=wishlist_product();
        saveWishlist(loggedInUser,wishlisted_items);
        break;
    case 9:
        displayWishlist(loggedInUser);
        break;
    case 10:
        cout<<"See You Soon !"<<endl;
        return 0;
    }
    goto A;
    clear_products();
    return 0;
}
