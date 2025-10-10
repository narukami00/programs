#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data, Node* next=nullptr, Node* prev=nullptr):data(data),next(next),prev(prev){}
};

class Functions{
    public:
    Node* head;
    Node* tail;
    int c;

    Functions(Node* head):head(head),tail(head),c(1){}
    Functions():head(nullptr),tail(nullptr),c(0){}

    void insert_at(int val, int pos){
        Node* new_node=new Node(val);
        if(pos==0){
            if(head==nullptr && tail==nullptr){
                head=tail=new_node;
            }else{
                head->prev=new_node;
                new_node->next=head;
                head=new_node;
            }
            c++;
            return;
        }
        if(pos==c){
            tail->next=new_node;
            new_node->prev=tail;
            tail=new_node;
            c++;
            return;
        }
        if(pos<0 || pos>c) return;

        Node* temp;
        if(pos>c/2){
            temp=tail;
            for(int i=c-1;i>pos;i--){
                temp=temp->prev;
            }
        }else{
            temp=head;
            for(int i=0;i<pos;i++){
                temp=temp->next;
            }
        }

        new_node->next=temp;
        new_node->prev=temp->prev;
        if(temp->prev) temp->prev->next=new_node;
        temp->prev=new_node;
        c++;
    }

    void delete_at(int pos){
        if(pos<0 || pos>=c) return;

        Node* temp;
        if(pos==0){
            temp=head;
            head=head->next;
            if(head) head->prev=nullptr;
            else tail=nullptr;
            delete temp;
            c--;
            return;
        }

        if(pos==c-1){
            temp=tail;
            tail=tail->prev;
            if(tail) tail->next=nullptr;
            else head=nullptr;
            delete temp;
            c--;
            return;
        }

        if(pos>c/2){
            temp=tail;
            for(int i=c-1;i>pos;i--){
                temp=temp->prev;
            }
        }else{
            temp=head;
            for(int i=0;i<pos;i++){
                temp=temp->next;
            }
        }

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        c--;
    }

    void print_at(int pos){
        if(pos<0 || pos>=c) return;

        Node* temp;
        if(pos>c/2){
            temp=tail;
            for(int i=c-1;i>pos;i--){
                temp=temp->prev;
            }
        }else{
            temp=head;
            for(int i=0;i<pos;i++){
                temp=temp->next;
            }
        }

        cout<<temp->data<<endl;
    }

    void update_at(int val, int pos){
        if(pos<0 || pos>=c) return;

        Node* temp;
        if(pos>c/2){
            temp=tail;
            for(int i=c-1;i>pos;i--){
                temp=temp->prev;
            }
        }else{
            temp=head;
            for(int i=0;i<pos;i++){
                temp=temp->next;
            }
        }

        temp->data=val;
    }
};

int32_t main(){
    Flashyy
    int t;
    cin>>t;
    char op;
    int n;
    Functions object;
    int pos=0;
    while(t--){
        cin>>op;
        if(op=='<') pos=max(0LL,pos-1);
        else if(op=='>') pos=min(object.c-1,pos+1);
        else if(op=='='){
            cin>>n;
            object.update_at(n,pos);
        }
        else if(op=='+'){
            cin>>n;
            object.insert_at(n,pos);
        }
        else if(op=='-'){
            object.delete_at(pos);
            pos=min(object.c-1,pos);
        }
        else if(op=='!'){
            object.print_at(pos);
        }
    }
    return 0;
}
