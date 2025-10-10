#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int value,Node* next):value(value),next(next){}
    Node(int value):value(value),next(nullptr){}
    ~Node(){};
};

Node* arrtoLL(vector<int> &arr){
    Node *head= new Node(arr[0],nullptr);
    Node *mover=head;

    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

Node* insertbefore(Node* head, int el, int k){
    if(head==NULL){
        if(k==1) return new Node(el);
        else return head;
    }
    if(k==1){return new Node(el,head);}

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* x= new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertafter(Node* head, int el, int k){
    if(head==NULL){
        if(k==1) return new Node(el);
        else return head;
    }
    if(k==1){return new Node(el,head);}

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            Node* x= new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertHead(Node* head,int el){
    return new Node(el,head);
}

Node* insertTail(Node* head,int el){
    if(head==NULL) return new Node(el);
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* new_node= new Node(el);
    temp->next=new_node;
    return head;
}

Node* insertBeforeElement(Node* head,int old_el,int new_el){
    Node*temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(temp->value==old_el){
            return insertbefore(head,new_el,cnt);
        }
        temp=temp->next;
    }
    return NULL;
}

Node* insertAfterElement(Node* head,int old_el,int new_el){
    Node*temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(temp->value==old_el){
            return insertafter(head,new_el,cnt);
        }
        temp=temp->next;
    }
    return NULL;
}

Node* remove(Node* head,int k){
    if(head==NULL)return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeHead(Node* head){
    if(head==NULL)return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* removeTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=nullptr;
    return head;
}

Node* removeBeforeElement(Node* head,int el){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(temp->value==el){
            return remove(head,cnt-1);
        }
        temp=temp->next;
    }
    return NULL;
}

Node* removeAfterElement(Node* head,int el){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(temp->value==el){
            return remove(head,cnt+1);
        }
        temp=temp->next;
    }
    return NULL;
}

void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* head= arrtoLL(arr);
    printLL(head);

    head=insertHead(head,9);
    printLL(head);
    head=insertTail(head,7);
    printLL(head);
    head=insertbefore(head,55,2);
    printLL(head);
    head=insertafter(head,55,3);
    printLL(head);
    head=insertBeforeElement(head,5,66);
    printLL(head);
    head=insertAfterElement(head,5,66);
    printLL(head);

    head=remove(head,2);
    printLL(head);
    head=removeHead(head);
    printLL(head);
    head=removeTail(head);
    printLL(head);
    head=removeBeforeElement(head,2);
    printLL(head);
    head=removeAfterElement(head,3);
    printLL(head);

    return 0;
}