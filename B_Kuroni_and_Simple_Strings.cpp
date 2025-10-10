#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    
        ll n, k;
        ll i = 0, j = 0,f=0;
        ll cnt = 0, sum = 0;
        string s ;vector<ll>v;
        
        cin>>s;
        
        ll a =0,b=s.size()-1;
        while(a<=b){
            if(f){
                if(s[b]==')') f=0,cnt+=2,v.push_back(a),v.push_back(b+1);
                b--;
            }
            else {
               if(s[a]=='(') f=1;
                a++; 
            }
        }
    
       sort(v.begin(),v.end());
       if(cnt) {cout<<1<<endl<<cnt<<endl;for(auto u : v) cout<<u<<" ";cout<<endl;
       }else cout<<cnt<<endl;
}
