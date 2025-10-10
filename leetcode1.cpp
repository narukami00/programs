#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      long long val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(long long x) : val(x), next(nullptr) {}
      ListNode(long long x, ListNode *next) : val(x), next(next) {}
  };


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<long long> num1;
        vector<long long> num2;

        ListNode* temp= l1;
        while(temp!=NULL){
            num1.push_back(temp->val);
            temp=temp->next;
        }

        ListNode* temp1= l2;
        while(temp1!=NULL){
            num2.push_back(temp1->val);
            temp1=temp1->next;
        }
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        long long n1=0,n2=0;

        for (long long i=0;i<num1.size(); i++)n1=n1*10+num1[i]; 
        for (long long i=0;i<num2.size(); i++)n2=n2*10+num2[i]; 

        long long s=n1+n2;

        if(s==0)return new ListNode(0);
        
        vector<long long> sum;
        while(s>0){
            long long digit= s%10;
            sum.push_back(digit);
            s/=10;
        }

        ListNode* head= new ListNode(sum[0]);
        ListNode* mover= head;
        for(long long i=1;i<sum.size();i++){
            ListNode* temp= new ListNode(sum[i]);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }


int main(){
    ListNode* l1= new ListNode(2,new ListNode(4,new ListNode(3)));
    ListNode* l2= new ListNode(5,new ListNode(6,new ListNode(4)));

    ListNode* l3=addTwoNumbers(l1,l2);

    ListNode* temp=l3;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}