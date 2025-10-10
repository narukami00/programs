// Smaller Super Shop

#include <bits/stdc++.h>
#include <typeinfo>
#include<cstring>
using namespace std;

class Multiplan;
vector<pair<string, int>> purchased_items;
vector<Multiplan*> products;

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
    virtual ~Multiplan() {}
};
class pc_parts : public Multiplan
{
public:
    pc_parts(const string &id,const string &name,double price): Multiplan(id,name, price) {}
};

class ram : public pc_parts
{
public:
    ram(const string &id,const string &name, double price):pc_parts(id,name,price) {}
};

class cpu : public pc_parts
{
public:
    cpu(const string &id,const string &name, double price):pc_parts(id,name,price) {}
};
class gpu : public pc_parts
{
public:
    gpu(const string &id,const string &name, double price):pc_parts(id,name,price) {}

};

class laptop : public Multiplan
{
public:
    laptop(const string &id,const string &name,double price): Multiplan(id,name, price) {}
};
class accessory : public Multiplan
{
public:
    accessory(const string &id,const string &name,double price): Multiplan(id,name, price) {}
};
class keyboard : public accessory
{
public:
    keyboard(const string &id,const string &name,double price): accessory(id,name, price) {}
};
class mouse : public accessory
{
public:
    mouse(const string &id,const string &name,double price): accessory(id,name, price) {}
};


template<typename T>
T* crtObj(string id, string s, double d)
{
    T* obj = new T(id,s,d);
    products.push_back(obj);
    return obj;
}


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


void clear_products()
{
    for (auto& product : products)
    {
        delete product;
    }
    products.clear();
}

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





int main()
{
    cout<<"Welcome to Super Tech Shop"<<endl;

A:
    cout<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<"1.Add Product\n2.Add Products from File\n3.Save Products to File\n4.Display Products\n5.Buy Products\n6.View Bill\n7.Print Bill\n8.Exit\n\nEnter your choice : ";
    int i;
    cin>>i;
    switch(i)
    {
    case 1:
        add_product();
        break;
    case 2:
        read_from_file("prod.txt");
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
        return  0;
    }
    goto A;
    clear_products();
    return 0;
}
