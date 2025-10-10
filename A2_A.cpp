#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char data):data(data),next(nullptr){}
};

void solve(){
    Node* head= nullptr;
    Node* temp= nullptr;

    string s;
    getline(cin,s);
    
    for(auto it:s){
        if(it=='(' || it=='['){
            temp=new Node(it);
            temp->next=head;
            head=temp;
        }else{
            if(it==')'){
                if(head==nullptr || head->data=='['){
                    cout<<"No\n";
                    return;
                }
                Node* del= head;
                head=head->next;
                delete del;
            }else if(it==']'){
                if(head==nullptr || head->data=='('){
                    cout<<"No\n";
                    return;
                }
                Node* del= head;
                head=head->next;
                delete del;
            }
        }
    }
    if(head==nullptr) cout<<"Yes\n";
    else cout<<"No\n";
    return;
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        solve();
    }
}