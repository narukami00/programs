#include <bits/stdc++.h>
#include<typeinfo>
using namespace std;

class TechShop;
vector<TechShop*> products;

class TechShop{
    protected:
    string id,name;
    double price;

    public:
    TechShop(const string &id,const string &name,double price):id(id),name(name),price(price){}
    string GetID(){return id;}
    string GetName(){return name;}
    double GetPrice(){return price;}

    void setID(const string &id){this->id=id;}
    void setName(const string &name){this->name=name;}
    void setPrice(double price){this->price=price;}

    virtual void display_info() const=0;
    friend ostream& operator<<(ostream &oc,const TechShop &product);

    virtual ~TechShop(){}
};

ostream& operator<<(ostream &oc,const TechShop &product){
    oc<<"ID : "<<product.id<<"\nModel Name : "<<product.name<<"\nPrice per unit : "<<product.price<<endl;
    return oc;
    }

class mobile : public TechShop{
public:
    mobile(const string &id,const string &name,double price):TechShop(id,name,price){};
    void display_info()const override{
    cout<<"Mobile "<<*this<<endl;
    }
};

class laptop : public TechShop{
public:
    laptop(const string &id,const string &name,double price):TechShop(id,name,price){};
    void display_info()const override{
    cout<<"Mobile "<<*this<<endl;
    }
};

class accessory : public TechShop{
public:
    accessory(const string &id,const string &name,double price):TechShop(id,name,price){};
    void display_info() const override{
    cout<<"Mobile "<<*this<<endl;
    }
};

template <class T>
T* create_object(const string &id,const string &name,double price){
    T* object= new T(id,name,price);
    products.push_back(object);
    return object;
}

void add_products(){
    string id,name;
    double price;

    cout<<"\n\nWhat kind of product you want to add?\n1.Mobile phone\n2.Laptop\n3.Accessory\nEnter Your Choice : ";
    int i;
    cin>>i;
    try{
    if(i==1){
        cout<<"Mobile ID : ";
        cin>>id;
        cin.ignore();
        cout<<"Model Name : ";
        getline(cin,name);
        cout<<"Price per unit : ";
        cin>>price;
        mobile *object=create_object<mobile>(id,name,price);
    }
    else if(i==2){
        cout<<"Laptop ID : ";
        cin>>id;
        cin.ignore();
        cout<<"Model Name : ";
        getline(cin,name);
        cout<<"Price per unit : ";
        cin>>price;
        laptop *object=create_object<laptop>(id,name,price);
    }
    else if(i==3){
        cout<<"Accessory ID : ";
        cin>>id;
        cin.ignore();
        cout<<"Model Name : ";
        getline(cin,name);
        cout<<"Price per unit : ";
        cin>>price;
        accessory *object=create_object<accessory>(id,name,price);
    }
    else throw i;}
    catch(int i){cout<<"\n\nEnter a valid input.\n\n";}

    cout<<"\n\nProduct Added Successfully.\n";

}

void save_to_file(const string &filename){
    ofstream fout(filename);
    for(const auto &product : products){

        if(dynamic_cast<mobile*>(product))fout<<"mobile,";
        else if(dynamic_cast<laptop*>(product))fout<<"laptop,";
        else if(dynamic_cast<accessory*>(product))fout<<"accessory,";

        fout<<product->GetID()<<","<<product->GetName()<<","<<product->GetPrice()<<endl;
    }

    cout<<"\n\nProduct Information saved to " << filename <<endl;
}

void display_products(){

    cout<<"\nAvailable Products in TechShop : \n\n";
    for(const auto &product : products){
        cout.width(40);
        cout.setf(ios::left,ios::adjustfield);
        if(dynamic_cast<mobile*>(product))cout<<"Product Type : Mobile ";
        else if(dynamic_cast<laptop*>(product))cout<<"Product Type : Laptop ";
        else if(dynamic_cast<accessory*>(product))cout<<"Product Type : Accessory ";

        cout<<"ID : "<<product->GetID()<<"               Name : "<<product->GetName()<<"            \tPrice : "<<product->GetPrice()<<endl;
    }
}

void load_from_file(const string &filename){
    ifstream fin(filename);
    string type,id,name,line;
    double price;

    while(getline(fin,line)){
        stringstream ss(line);
        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,name,',');
        ss>>price;

        if(type=="mobile") mobile *object=create_object<mobile>(id,name,price);
        else if(type=="laptop") laptop *object=create_object<laptop>(id,name,price);
        else if(type=="accessory") accessory *object=create_object<accessory>(id,name,price);
    }

    cout<<"\n\nProduct Information loaded from "<<filename<<endl;
}

void clear_products(){
    for(const auto &product : products)delete product;
    products.clear();
}

void search_by_id(){
    string id;
    cout<<"\n\nEnter ID of Product you want to find : ";
    cin>>id;
    for(const auto &product : products){
        if(product->GetID()==id){
            product->display_info();
            return;
        }
    }
    cout<<"Product with ID "<<id<< " not found.";
}

void edit_product(){
    string id,name;
    double price;

    TechShop *product_to_edit = nullptr;

    cout<<"\n\nEnter Product ID You Want to Modify : ";
    cin>>id;
    cin.ignore();

    for(const auto product : products){
        if(product->GetID()==id){
            product_to_edit=product;
            break;
        }
    }

    try{if(product_to_edit==nullptr)throw id;}
    catch(const string &id){cout<<"Product with ID "<<id<<" not found.";}

    cout<<"\n1.Edit Product\n2.Delete Product\nEnter choice :";
    int i;
    cin>>i;
    if(i==1){
        cout<<"\n1.Edit ID\n2.Edit Name\n3.Edit Price\n\nEnter Your Choice : ";
        int j;
        cin>>j;
        cin.ignore();
        if(j==1){
            cout<<"Enter New ID : ";
            string new_id;
            cin>>new_id;
            product_to_edit->setID(new_id);
        }
        else if(j==2){
            cout<<"Enter New Name : ";
            string new_name;
            getline(cin,new_name);
            product_to_edit->setName(new_name);
        }
        else if(j==3){
            cout<<"Enter New Price : ";
            double new_price;
            cin>>new_price;
            product_to_edit->setPrice(new_price);
        }
        cout<<"\nProduct Information Edited Successfully.\n";
    }
    else if(i==2){
        auto it = find(products.begin(),products.end(),product_to_edit);
        if(it!=products.end())products.erase(it);
        cout<<"Product with id "<<id<<" has been deleted.";
    }
}


int main(){
    system("cls");
    cout<<"\n\nWelcome to Tech Shop\n\n";
    A:
    cout<<"\n\nWhat Do You Want To Do ?\n\n1.Add Product\n2.Display Products\n3.Save Product Information To File\n4.Load Product Information From File\n5.Search By ID\n6.Edit/Delete a Product\n7.Exit\n\nEnter Your Choice : ";
    int c;
    cin>>c;
    switch(c){
    case 1:
        system("cls");
        add_products();
        break;
    case 2:
        system("cls");
        display_products();
        break;
    case 3:
        system("cls");
        save_to_file("products.txt");
        break;
    case 4:
        system("cls");
        load_from_file("products.txt");
        break;
    case 5:
        search_by_id();
        break;
    case 6:
        system("cls");
        edit_product();
        break;
    case 7:
        system("cls");
        cout<<"\n\nThank You\n";
        clear_products();
        return 0;
    default:
        cout<<"\nEnter a valid input";
        break;
    }
    goto A;
}
