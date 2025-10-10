#include<bits/stdc++.h>
using namespace std;


int main(){
    int plabon,hirobi,newton;
    cin>>plabon>>hirobi>>newton;
    
    vector<int>robi_like(hirobi);
    vector<int>new_like(newton);
    vector<int>give(plabon,0);

    for(int i=0;i<hirobi;i++)cin>>robi_like[i];
    for(int i=0;i<newton;i++)cin>>new_like[i];
    
    for(int i=0;i<hirobi;i++)give[robi_like[i]-1]=1;
    for(int i=0;i<newton;i++)if(give[new_like[i]-1]==0)give[new_like[i]-1]=2;
    
    for(int i=0;i<plabon;i++){
        if(give[i]==0)give[i]=2;
        cout<<give[i];
        if(i!=plabon-1)cout<<" ";
    }
    
    return 0;
}