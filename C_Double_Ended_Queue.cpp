// #include<bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
//     Node* prev;
//     Node(int val=0):data(val),next(nullptr),prev(nullptr){}
// };

// struct DLL{
//     Node* head= nullptr;
//     Node* tail= nullptr;
//     int size;
//     int cnt=0;

//     DLL(int n):size(n){}

//     void pL(int val){
//         if(cnt ==size){
//             cout<<"The queue is full\n";
//             return;
//         }
//         Node* newNode = new Node(val);
//         if(head==nullptr && tail==nullptr){
//             head=newNode;
//             tail=newNode;
//         }else{
//             newNode->next=head;
//             head->prev=newNode;
//             head=newNode;
//         }cnt++;
//         cout<<"Pushed in left: "<<val<<endl;
//     }

//     void pR(int val){
//          if(cnt ==size){
//             cout<<"The queue is full\n";
//             return;
//         }
//         Node* newNode = new Node(val);
//         if(head==nullptr && tail==nullptr){
//             head=newNode;
//             tail=newNode;
//         }else{
//             tail->next=newNode;
//             newNode->prev=tail;
//             tail=newNode;
//         }cnt++;
//         cout<<"Pushed in right: "<<val<<endl;
//     }

//     void popL(){
//         if(head==nullptr && tail==nullptr){
//             cout<<"The queue is empty\n";
//             return;
//         }
//         Node* temp= head;
//         if(head==tail){
//             head=nullptr;
//             tail=nullptr;
//         }else{
//             head=head->next;
//             head->prev=nullptr;
//         }cout<<"Popped from left: "<<temp->data<<endl;
//         delete temp;
//         cnt--;
//     }

//     void popR(){
//         if(head==nullptr && tail==nullptr){
//             cout<<"The queue is empty\n";
//             return;
//         }
//         Node* temp= tail;
//         if(head==tail){
//             head=nullptr;
//             tail=nullptr;
//         }else{
//             tail=tail->prev;
//             tail->next=nullptr;
//         }cout<<"Popped from right: "<<temp->data<<endl;
//         delete temp;
//         cnt--;
//     }
    
// };

// int main(){
//     int t;
//     cin>>t;
//     for(int c=1;c<=t;c++){
//         int n,k;
//         cin>>n>>k;
//         DLL dll(n);
//         string s;
//         int x;
//         cout<<"Case "<<c<<":"<<endl;
//         while(k--){
//             cin>>s;
//             if(s=="pushLeft" || s=="pushRight"){
//                 cin>>x;
//                 if(s=="pushLeft")dll.pL(x);
//                 else dll.pR(x);
//             }else{
//                 if(s=="popLeft")dll.popL();
//                 else dll.popR();
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int si = 0;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *pushleft(node *head, node *tail, int d)
{
    node *n = new node{d, nullptr, nullptr};

    if (!head)
    {
        head = n;
    }
    else
    {

        n->next = head;
        head->prev = n;
        
    }

    //  cout<<  ;
    si++;
    return n;
}
node *pushright(node *head, node *tail, int d)
{
    node *n = new node{d, nullptr, nullptr};
    if (!tail)
    {

        tail = n;
    }
    else
    {

        n->prev = tail;
        tail->next = n;
    }
    //  cout<< ;
    si++;
    return n;
}

node *popright(node *head, node *tail, int d)
{
    cout << "Popped from right: " << tail->data << endl;
    si--;
    if (!si)
        return nullptr;

    tail->prev->next = nullptr;

    return tail->prev;
}

node *popleft(node *head, node *tail, int d)
{
    cout << "Popped from left: " << head->data << endl;
    si--;
    if (!si)
        return nullptr;
    head->next->prev = nullptr;

    return head->next;
}
void traverse(node *head)
{
    cout<<endl<<"travrsing"<<endl;
    node *temp = head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl<<"travrsing"<<endl;

}
int main()
{

    int t, i, x, n, m, k, z, l, j;
    cin >> t;

    for (i = 1; i <= t; i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        string s;
        map<string, int> mp;
        mp["pushLeft"] = 1;
        mp["pushRight"] = 2;
        mp["popLeft"] = 3;
        mp["popRight"] = 4;
        si=0;
        cin >> n >> m;
        node *head = nullptr;
        node *tail = head;
        while (m--)
        {
            
            cin >> s;

            // node *head =new node{0, nullptr, nullptr};

            if (mp[s] == 1)
            { // cout<<1<<endl;
                cin>>k;
                if (si == n)
                {
                    cout << "The queue is full" << endl;
                    continue;
                }
                head = pushleft(head, tail, k);

                if (si == 1)
                    tail = head;
                cout << "Pushed in left: " << k << endl;
            }
            else if (mp[s] == 2)
            { // cout<<2<<endl;
                cin>>k;
                if (si == n)
                {
                    cout << "The queue is full" << endl;
                    continue;
                }
                tail = pushright(head, tail, k);
                if (si == 1)
                    head = tail;

                cout << "Pushed in right: " << k << endl;
            }
            else if (mp[s] == 3)
            {
                if (si == 0)
                {
                    cout << "The queue is empty" << endl;
                    continue;
                }
                head = popleft(head, tail, k);
                if (si == 0 || si == 1){
                    tail = head;}
            }
            else if (mp[s] == 4)
            {
                if (si == 0)
                {
                    cout << "The queue is empty" << endl;
                    continue;
                }
                tail = popright(head, tail, k);
                if (si == 0 || si == 1){
                    head = tail;}
            }
            //traverse(head);
        }
    }
}
