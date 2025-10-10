#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX=1e6+1;
set<ll> prime_square(){
    static bool arr[MAX];
    for(int i=2;i*i<MAX;i++){
        if(!arr[i]){
            for(int j=i*i;j<MAX;j+=i){
                arr[j]=true;
            }
        }
    }
    set<ll> res;
    for(int i=2;i<MAX;i++){
        if(!arr[i]){
            res.insert((ll)i*i);
        }
    }
    return res;
}
int main(){
    set<ll> s(prime_square());
    ll n; cin >> n;
    while(n--){
        ll t;
        cin>>t;
        if(s.find(t)!=s.end())cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}