#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve(int tc){

    ll a, b, c;
    cin>>a>>b>>c;
    ll s= (a+b+c);//s as 2s
    ll up=(s-2*a)*(s-2*b)*(s-2*c);
    ll g=gcd(up,(4*s));
    cout<<up/g<<"/"<<4*s/g;
    // if(tc!=0)
    cout<<endl;


}
int main(){
    int t; cin >> t;
    while(t--) solve(t);
    return 0;
}