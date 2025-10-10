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
    if(stoll(s)<33){
        no;
        return;
    }
    while(true){
        for(int i=0;i<n-1 && n>2;){
            if(s[i]=='3'&& s[i+1]=='3'){
                s.erase(i,2);
                n=s.size();
            }
            else i++;
        }
        int k=stoll(s);
        if(k>=33)k-=33;
        if(k==0){
            yes;
            return;
        }
        if(k<33)break;
        s=to_string(k);
        n=s.size();
    }
    no;
    return;

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