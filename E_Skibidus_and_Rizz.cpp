#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        int f=0;
        cin>>n>>m>>k;
        vector<int>ans;
        
        if(k>max(n,m) || k<abs(n-m))cout<<"-1"<<endl;
        else{
            if(n>=m){
                for(int i=0;i<k;i++){
                    ans.push_back(0);
                }
                n-=k;
                while(n && m){
                    ans.push_back(1);
                    ans.push_back(0);
                    n--;
                    m--;
                }
                for(int i=0;i<m;i++) ans.push_back(1);
                for(int i=0;i<n;i++)ans.push_back(0);
            }
            else{
                for(int i=0;i<k;i++){
                    ans.push_back(1);
                }
                m-=k;
                while(n && m){
                    ans.push_back(0);
                    ans.push_back(1);
                    n--;
                    m--;
                }
                for(int i=0;i<m;i++) ans.push_back(1);
                for(int i=0;i<n;i++)ans.push_back(0);
            }

            for(int i=0;i<ans.size();i++)cout<<ans[i];
            cout<<endl;
        }

    }
}