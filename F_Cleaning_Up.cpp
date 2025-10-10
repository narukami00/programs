#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> c,a,d;
        int n,m,di=0;
        bool flg=true;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int f;
            cin>>f;
            d.push_back(f);
        }
        sort(d.begin(),d.end());
        for(int i=0;i<n;i++){
            if(di<d.size()&&d[di]==i+1){
                di++;
                continue;
            }
            if(flg) c.push_back(i+1);
            else a.push_back(i+1);
            flg=!flg;
        }
        
        if(c.size()==0)cout<<"-1";
        else for(int i=0;i<c.size();i++)cout<<c[i]<<" ";
        cout<<endl;

        if(a.size()==0)cout<<"-1";
        else for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
        cout<<endl;
    }
}