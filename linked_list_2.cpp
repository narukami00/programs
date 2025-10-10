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

Node* swapAdj(Node* head){
    Node temp(0);
    temp.next=head;
    Node* prev=&temp;

    while(prev->next != nullptr && prev->next->next!=nullptr){
        Node* first=prev->next;
        Node* second=prev->next->next;

        first->next=second->next;
        second->next=first;
        prev->next=second;

        prev=first;
    }

    return temp.next;
}

int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* head= arrtoLL(arr);
    head=swapAdj(head);
    printLL(head);
    return 0;
}