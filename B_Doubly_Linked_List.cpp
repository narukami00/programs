#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

class Node{
public:

    int data;
    Node* prev;
    Node* next;

    Node(int data): data(data),prev(nullptr),next(nullptr){};
};

class Doubly{
    public:
    Node* head=nullptr;
    Node* tail=nullptr;

    void insertFirst(int v){
        Node* temp= new Node( v);
        temp->next=head;
        if(head!=nullptr)head->prev=temp;
        else tail=temp;
        head=temp;
    }

    void lastDelete(){
        if(tail==nullptr) return;
        else if(tail->prev==nullptr){
            head=tail=nullptr;
        }else{
            Node* temp= tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
        }
    }

    void firstDelete(){
        if(head==nullptr) return;
        else if(head->next==nullptr){
            head=tail=nullptr;
        }else{
            Node* temp= head;
            head= head->next;
            head->prev=nullptr;
            delete temp;
        }
    }

    void deleteNode(int v){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==v){
                if(temp==head) firstDelete();
                else if(temp==tail) lastDelete();
                else{
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp;
                }
                return;
            }
            temp=temp->next;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->next!=nullptr)cout<<temp->data<<" ";
            else cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
};

int32_t main(){
    FAST
    Doubly ll;
    int n;cin>>n;
    while(n--){
        string s;
        int v;
        cin>>s;
        if(s=="insert"){
            cin>>v;
            ll.insertFirst(v);
        }else if(s=="delete"){
            cin>>v;
            ll.deleteNode(v);
        }else if(s=="deleteFirst"){
            ll.firstDelete();
        }else{
            ll.lastDelete();   
        }
    }
    ll.display();
    return 0;
}