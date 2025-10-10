#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data):data(data),next(nullptr),prev(nullptr){}
};

class Functions{
public:
    Node* head;
    Node* tail;
    Node* current;
    int size;

    Functions():head(nullptr),tail(nullptr),current(nullptr),size(0){}

    void insert_at(int val){
        Node* new_node=new Node(val);
        if(size==0) {
            head=tail=current=new_node;
        }else{
            new_node->next=current;
            new_node->prev=current->prev;
            if(current->prev){
                current->prev->next=new_node;
            }else{
                head=new_node;
            }
            current->prev=new_node;
            current=new_node;
        }
        size++;
    }

    void delete_at(){
        if(current==nullptr)return;
        Node* temp=current;
        if(current->next) {
            current=current->next;
            if(temp->prev){
                temp->prev->next=current;
                current->prev=temp->prev;
            }else{
                head=current;
                current->prev=nullptr;
            }
        }else{
            current=current->prev;
            if(current){
                current->next=nullptr;
                tail=current;
            }else{
                head=tail=nullptr;
            }
        }
        delete temp;
        size--;
    }

    void update_at(int val){
        if(current==nullptr) return;
        current->data=val;
    }

    void print_at(){
        if(current==nullptr) return;
        cout<<current->data<<endl;
    }

    void move_prev(){
        if(current && current->prev) {
            current=current->prev;
        }
    }

    void move_next(){
        if(current && current->next) {
            current=current->next;
        }
    }
};

int32_t main(){
    Flashyy
    int t;
    cin>>t;
    char op;
    int n;
    Functions object;
    while(t--) {
        cin>>op;
        if(op=='<') object.move_prev();
        else if(op=='>') object.move_next();
        else if(op=='='){
            cin>>n;
            object.update_at(n);
        }
        else if(op=='+'){
            cin>>n;
            object.insert_at(n);
        }
        else if(op=='-'){
            object.delete_at();
        }
        else if(op=='!'){
            object.print_at();
        }
    }
    return 0;
}
