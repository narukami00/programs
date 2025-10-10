#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)


void solve(string s){
    int n=s.size();
    if(n==1){cout<<"1 1 1 1"<<endl;return;}

    int final_l=0,final_r=0;
    string ans;

    for(int r=0;r<n;r++){
        string test=s;
        int ll=r;
        for(int l=r;l>=0;l--){
            if(s[l]=='1')test[n-1-(r-l)]^=1;
            if(test[n-1-(r-l)]=='1')ll=l;
        }
        test=s;
        for(int l=r;l>=ll;l--){
            if(s[l]=='1')test[n-1-(r-l)]^=1;
        }
        if(test>ans){
            ans=test;
            final_l=ll+1,final_r=r+1;
        }
    }
    cout<<"1 "<<n<<" "<<final_l<<" "<<final_r<<endl;
}
int32_t main(){
    Flashyy
    tc
    {
        string s;
        cin>>s;
        solve(s);
    }
return 0;
}