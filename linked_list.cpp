#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1):data(data1),next(next1){}
    Node(int data1):data(data1),next(nullptr){}
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

int lengthLL(Node* head){
    Node* temp=head;
    int c=0;
    while(temp){
        temp=temp->next;
        c++;
    }
    return c;
}

int checkPresent(Node*head,int val){
    Node* temp= head;
    while(temp){
        if(temp->data==val)return 1;
        temp=temp->next;
    }
    return 0;
}

Node* removeK(Node* head, int k){
    if(head==NULL)return head;
    if(k==1){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev= temp;
        temp=temp->next;
    }
    return head;
}

Node* insertK(Node*head,int element, int k){
    if(head==NULL){
        if(k==1)return new Node(element);
        else return head;
    }
    if(k==1){return new Node(element,head);}

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* x = new Node(element, temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)cin>>arr[i];
    Node* head=arrtoLL(arr);
    while (true)
    {  
    cout<<endl<<endl;
    cout<<"1.Insert \n2.Delete\n3.Display\n4.Length\n5.Search\n6.Exit\n\nEnter your choice : ";
    int c;
    cin>>c;
    cout<<endl;
    switch (c)
    {
    case 1:
        int el,k;
        cout<<"Enter element to insert : ";cin>>el;
        cout<<"Enter position to insert to : ";cin>>k;
        head=insertK(head,el,k);
        break;
    case 2:
        int p;
        cout<<"Enter position to delete : ";cin>>p;
        head=removeK(head,p);
        break;
    case 3:
        cout<<"Elements currently : ";
        printLL(head);
        break;
    case 4:
        cout<<"Current length : ";
        cout<<lengthLL(head)<<endl;
        break;
    case 5:
        int s;
        cout<<"Enter element to search for : ";cin>>s;
        if(checkPresent(head,s))cout<<"Found !"<<endl;
        else cout<<"Not found :("<<endl; 
        break;
    case 6:
        cout<<"Byeee!"<<endl;
        return 0;        
    default:
        cout<<"Enter Valid Input"<<endl;
        continue;;
    }
    }
    return 0;
}