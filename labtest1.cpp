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

Node* deleteFirst(Node* head){
    if(head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    temp->next->prev=nullptr;
    head=temp->next;
    delete temp;
    return head;
}

Node* deleteLast(Node* head){
if(head->next==NULL) return nullptr;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    delete temp;
    return head;
}

Node* insertFront(Node* head, int key){
    if(head==nullptr){
        Node* temp=new Node(key);
        return temp;
    }
    Node* temp=new Node(key);
    temp->next=head;
    head->prev=temp;
    return temp;
}

Node* removeFirstKey(Node* head, int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp==head){
                    if(head->next==nullptr){
                        return nullptr;
                    }
                temp->next->prev=nullptr;
                head=temp->next;
                delete temp;
                return head;
            }
            if(temp->next==nullptr){
                temp->prev->next=nullptr;
                delete temp;
                return head;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return head;
        }
        temp=temp->next;
    }
    return head;
}

void displayList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL)cout<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int32_t main(){
    Node* head= nullptr;

    //displayList(head);

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="insert"){
            int n;
            cin>>n;
            head=insertFront(head,n);
        }
        else if(s=="delete"){
            int n;
            cin>>n;
            head=removeFirstKey(head,n);
        }
        else if(s=="deleteFirst"){
            head= deleteFirst(head);
        }
        else if(s=="deleteLast"){
            head= deleteLast(head);
        }
    }
    displayList(head);
}
