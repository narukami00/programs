#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val):val(val),next(nullptr),prev(nullptr){}
};

Node* curr= new Node(0);

Node* insertLeft(Node* head, int value){
    if(curr && curr->prev){
        Node* newNode= new Node(value);
        newNode->next=curr;
        Node* temp=curr->prev;
        newNode->prev=curr->prev;
        curr->prev=newNode;
        temp->next=newNode;
        curr=curr->prev;
    }else{
        Node* newNode= new Node(value);
        newNode->next=curr;
        curr->prev=newNode;
        curr=curr->prev;
        head=newNode;
    }
    return head;
}

Node* insertRight(Node* head, int value){
    if(curr && curr->next){
        Node* newNode= new Node(value);
        Node* temp=curr->next;
        newNode->prev=curr;
        newNode->next=temp;
        curr->next=newNode;
        curr=curr->next;
    }else{
        Node* newNode= new Node(value);
        curr->next=newNode;
        newNode->prev=curr;
        curr=curr->next;
    }
    return head;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->val;
        if(temp->next!=nullptr)cout<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int32_t main(){
    Flashyy
    Node* head= curr;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='L'){
            head=insertLeft(head,i);
        }
        else{
            head=insertRight(head,i);
        }
    }
    display(head);
return 0;
}