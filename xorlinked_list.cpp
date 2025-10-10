#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* npx;
};

Node* XOR(Node* a,Node*b){
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(Node* &head, int data){
    Node* newNode= new Node();
    newNode->data=data;
    newNode->npx= XOR(head,nullptr);

    if(head!=nullptr){
        head->npx = XOR(newNode, XOR(head->npx,nullptr));
    }
    head= newNode;
}

void delNode(Node* head, Node* node){
    if(head==NULL || node== NULL) return;

    Node* prev= nullptr, *curr=head;
    Node* next= XOR(prev,curr->npx);

    while(curr){
        if(curr==node){
            if(next){
                next->npx=XOR(XOR(curr,next->npx),prev);
            }
            if(prev){
                prev->npx=XOR(XOR(curr,prev->npx),next);
            }
            if(curr==head){
                head=next;
            }
            delete curr;
            return;
        }
        prev=curr;
        curr=next;
        if(curr){
            next=XOR(prev,curr->npx);
        }
    }
}

void printList(Node* head){
    Node* curr=head, *prev= NULL;
    Node* next;
    cout<<"XOR Linked List Data : ";
    while(curr!=NULL){
        cout<<curr->data<<" ";
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
    cout<<endl;
}

int main(){
    Node* head=nullptr;

    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);

    printList(head);

    delNode(head,head->npx);
    printList(head);

    return 0;
}