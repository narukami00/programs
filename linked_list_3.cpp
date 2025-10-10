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

Node* mergeSortLL(Node* head1, Node* head2){
    Node temp(0);
    Node* tail=&temp;

    while(head1 != nullptr && head2!=nullptr){
        if(head1->data<=head2->data){
            tail->next=head1;
            head1=head1->next;
        }
        else{
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }

    if(head1!=nullptr) tail->next=head1;   
    else tail->next=head2;

    return temp.next;
}

int main(){
    vector<int> arr1={1,2,3,4,5,6};
    Node* head1= arrtoLL(arr1);
    vector<int> arr2={1,2,3,4,5,6};
    Node* head2= arrtoLL(arr2);

    printLL(head1);
    cout<<" + "<<endl;
    printLL(head2);
    cout<<" = "<<endl;
    printLL(mergeSortLL(head1,head2));

    return 0;
}