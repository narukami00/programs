#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

class TechShop;
vector<TechShop*> products;

class TechShop{
    protected:
    string id;
    string brand;
    string model;
    int price;

    public:
    TechShop(const string &id,const string &brand,const string &model,int price): id(id),brand(brand),model(model),price(price){}

    string getID(){return id;}
    string getBrand(){return brand;}
    string getModel(){return model;}
    int getPrice(){return price;}

    void setID(const string &id){this->id=id;}
    void setBrand(const string &brand){this->brand=brand;}
    void setModel(const string &model){this->model=model;}
    void setPrice(int price){this->price=price;}

    friend ostream& operator<<(ostream &os, const TechShop &product);

    virtual void displayDetails() const = 0;
    virtual ~TechShop(){}
};

ostream& operator<<(ostream &os, const TechShop &product) {
    os << "ID: " << product.id << "\nBrand: " << product.brand << "\nModel: " << product.model << "\nPrice: " << product.price << ".00";
    return os;
}

class mobile : public TechShop{
    public:
    mobile(const string &id,const string &brand,const string &model,int price):TechShop(id,brand,model,price){}
    void displayDetails() const override {
        cout << "Mobile Phone " << *this << endl;
    }
};

class laptop : public TechShop{
    public:
    laptop(const string &id,const string &brand,const string &model,int price):TechShop(id,brand,model,price){}
    void displayDetails() const override {
        cout << "Laptop " << *this << endl;
    }
};

class cpu : public TechShop{
    public:
    cpu(const string &id,const string &brand,const string &model,int price):TechShop(id,brand,model,price){}
    void displayDetails() const override {
        cout << "CPU " << *this << endl;
    }
};

class gpu : public TechShop{
    public:
    gpu(const string &id,const string &brand,const string &model,int price):TechShop(id,brand,model,price){}
    void displayDetails() const override {
        cout << "GPU " << *this << endl;
    }
};

class ram : public TechShop{
    public:
    ram(const string &id,const string &brand,const string &model,int price):TechShop(id,brand,model,price){}
    void displayDetails() const override {
        cout << "RAM " << *this << endl;
    }
};

template<typename T>
T* crtObj(string id, string brand, string model,int price){
    T* obj = new T(id,brand,model,price);
    products.push_back(obj);
    return obj;
}

void add_product(){
    cout<<"HOW MANY PRODUCTS? : ";
    int n,m,price;
    string id,brand,model;
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++){
        cout<<"\nWHAT KIND OF PRODUCT? : \n1.Mobile phone\n2.Laptop\n3.CPU\n4.GPU\n5.RAM\nENTER YOUR CHOICE : ";
        cin>>m;
        cout<<"NB:ID MUST BE A SINGLE WORD WITH LETTERS AND NUMBERS\n";

        if(m==1){
            cout<<"Mobile ID : ";
            cin>>id;
            cout<<"Mobile Brand : ";
            cin.ignore();
            getline(cin,brand); 
            cout<<"Mobile Model : ";
            //cin.ignore();
            getline(cin,model);
            cout<<"Mobile Price : ";
            cin>>price;
            mobile *obj= crtObj<mobile>(id,brand,model,price);
        }

        else if(m==2){
            cout<<"Laptop ID : ";
            cin>>id;
            cout<<"Laptop Brand : ";
            cin.ignore();
            getline(cin,brand); 
            cout<<"Laptop Model : ";
            //cin.ignore();
            getline(cin,model);
            cout<<"Laptop Price : ";
            cin>>price;
            laptop *obj= crtObj<laptop>(id,brand,model,price);
        }

        else if(m==3){
            cout<<"CPU ID : ";
            cin>>id;
            cout<<"CPU Brand : ";
            cin.ignore();
            getline(cin,brand); 
            cout<<"CPU Model : ";
            //cin.ignore();
            getline(cin,model);
            cout<<"CPU Price : ";
            cin>>price;
            cpu *obj= crtObj<cpu>(id,brand,model,price);
        }

        else if (m==4){
            cout<<"GPU ID : ";
            cin>>id;
            cout<<"GPU Brand : ";
            cin.ignore();
            getline(cin,brand); 
            cout<<"GPU Model : ";
            //cin.ignore();
            getline(cin,model);
            cout<<"GPU Price : ";
            cin>>price;
            gpu *obj= crtObj<gpu>(id,brand,model,price);
        }

        else if(m==5){
            cout<<"RAM ID : ";
            cin>>id;
            cout<<"RAM Brand : ";
            cin.ignore();
            getline(cin,brand); 
            cout<<"RAM Model : ";
            //cin.ignore();
            getline(cin,model);
            cout<<"RAM Price : ";
            cin>>price;
            ram *obj= crtObj<ram>(id,brand,model,price);
        }
    }
    cout<<"\n\n"<<n<<" Product(s) Added Successfully\n";
}

void display_products(){

    cout<<"\nAvailable Products in Mini Tech Shop :\n\n";
    for(const auto &product : products){
        cout.width(40);
        cout.setf(ios::left,ios::adjustfield);

        if(dynamic_cast<mobile*>(product)) cout<<"Product : Mobile Phone";
        else if(dynamic_cast<laptop*>(product)) cout<<"Product : Laptop"; 
        else if(dynamic_cast<cpu*>(product)) cout<<"Product : CPU\t";
        else if(dynamic_cast<gpu*>(product)) cout<<"Product : GPU\t";
        else if(dynamic_cast<ram*>(product)) cout<<"Product : RAM\t";

        cout<<"\t ID : "<<product->getID()<<"\t\t Brand : "<<product->getBrand()<<"    \t\t Model : "<<product->getModel()<<"     \t\t Price : "<<product->getPrice()<<".00"<<endl;    
    }
}

void search_by_id(){
    cout<<"Enter ID of Product You Want to Search : ";
    string searchID;
    cin>>searchID;

    for (const auto &product : products) {
        if (product->getID() == searchID) {
            product->displayDetails();
            return;
        }
    }
    cout << "Product with ID " << searchID << " not found." << endl;

}

void clear_products(){
    for(auto &product : products){delete product;}
    products.clear();
}

void save_to_file(const string &filename){
    ofstream outfile(filename);
    if(!outfile.is_open()){cout<<"Error Opening File\n";return;}

    for(const auto &product : products){
        if(dynamic_cast<mobile*>(product)) outfile<<"mobile,";
        else if(dynamic_cast<laptop*>(product)) outfile<<"laptop,";
        else if(dynamic_cast<cpu*>(product)) outfile<<"cpu,";
        else if(dynamic_cast<gpu*>(product)) outfile<<"gpu,";
        else if(dynamic_cast<ram*>(product)) outfile<<"ram,";

        outfile<<product->getID()<<","<<product->getBrand()<<","<<product->getModel()<<","<<product->getPrice()<<endl;
    }    
    outfile.close();
    cout<<"\nProduct Information Saved To "<<filename<<endl;
}

void read_from_file(const string &filename){
    ifstream infile(filename);
    if(!infile.is_open()){cout<<"Error Opening File\n";return;}

    string type,id,brand,model,line;
    int price;

    while(getline(infile,line)){
        stringstream ss(line);
        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,brand,',');
        getline(ss,model,',');
        ss>>price;
        if(type=="mobile") mobile *obj= crtObj<mobile>(id,brand,model,price);
        else if(type=="laptop") laptop *obj= crtObj<laptop>(id,brand,model,price);
        else if(type=="cpu") cpu *obj= crtObj<cpu>(id,brand,model,price);
        else if(type=="gpu") gpu *obj= crtObj<gpu>(id,brand,model,price);
        else if(type=="ram") ram *obj= crtObj<ram>(id,brand,model,price);
    }
    infile.close();
    cout<<"\n\nPRODUCT INFORMATION LOADED FROM "<<filename<<"\n\n";
}

void edit_product(){
    cout<<"Enter Product ID to Edit/Delete : ";
    string id;
    cin>>id;

    TechShop* product_to_edit=nullptr;

    for(auto& product:products){
            if(product->getID()==id){
            product_to_edit=product;
            break;
        }
    }
    
    try{if(product_to_edit==nullptr)throw id;}
    catch(string id){cout<<"Product With ID : "<<id<<" Not Found.\n";return;}

    cout<<"Enter Choice:\n1.Edit Product\n2.Delete Product\n: ";
    int choice;
    cin>>choice;
    cin.ignore();
    if(choice==1){
        cout<<"\n1.ID\n2.Brand\n3.Model\n4.Price\n Your Choice: ";
        int edit;
        cin>>edit;
        cin.ignore();

        if(edit==1){
            cout<<"New ID : ";
            string new_id;
            cin>>new_id;
            product_to_edit->setID(new_id);
        }
        else if(edit==2){
            cout<<"New Brand : ";
            string new_brand;
            //cin.ignore();
            getline(cin,new_brand);
            product_to_edit->setBrand(new_brand);
        }    
        else if(edit==3){
            cout<<"New Model : ";
            string new_model;
            //cin.ignore();
            getline(cin,new_model);
            product_to_edit->setModel(new_model);
        } 
        else if(edit==4){
            cout<<"New Price : ";
            int new_price;
            cin>>new_price;
            product_to_edit->setPrice(new_price);
        } 

        cout<<"\nProduct Information Updated Successfully"<<endl;
    }

    else if(choice==2){
        auto it =find(products.begin(),products.end(),product_to_edit);
        if(it!=products.end()){
            products.erase(it);
            cout<<"\nProduct Deleted Successfully"<<endl;
        }
    }
}

int main(){
    system("cls");
    cout<<"\n\nWELCOME TO MINI TECH SHOP\n";
    A:
    cout<<"\nYour Choice:\n1.Add Products\n2.Dsiplay Products\n3.Edit/Delete Product\n4.Save Current Data To File\n5.Load Existing Data From File\n6.Search by ID\n7.Exit\n: ";
    int i;
    cin>>i;
    cout<<endl;
    switch(i){
        case 1:
        system("cls");
        add_product();
        break;
        case 2:
        system("cls");
        display_products();
        break;
        case 3:
        system("cls");
        edit_product();
        break;
        case 4:
        system("cls");
        save_to_file("products.txt");
        break;
        case 5:
        system("cls");
        read_from_file("products.txt");
        break;
        case 6:
        system("cls");
        search_by_id();
        break;
        case 7:
        system("cls");
        cout<<"THANK YOU !!!\n\n"<<endl;
        clear_products();
        return 0;
    }
    goto A;
}    