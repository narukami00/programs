#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1):data(data1),next(next1){}
    Node(int data1):data(data1),next(nullptr){}
    ~Node(){};
};

Node* arrtoLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


Node* removeDups(Node* head){
    if(head==NULL) return head;

    Node* temp=head;
    int first=temp->data;

    while(temp && temp->next){
        if(temp->next->data==first){
            Node* x=temp->next;
            temp->next=temp->next->next;
            delete x;
        }
        else{
            first=temp->next->data;
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr={1,1,1,1,1,1};
    Node* head= arrtoLL(arr);
    head=removeDups(head);
    printLL(head);
    return 0;
}
