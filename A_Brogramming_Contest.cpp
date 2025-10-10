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
void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;

    bool zero=true;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            zero=false;
            break;
        }
    }

    if(zero){
        cout<<"0"<<endl;
        return;
    }

    int grp=1;
    for(int i=1;i<n;i++){
        if(s[i-1]!=s[i]){
            grp++;
        }
    }

    if(s[0]=='1'){
        cout<<grp<<endl;
        return;
    }else{
        cout<<grp-1<<endl;
        return;
    }
}
int32_t main(){
    Flashyy
    tc
    {
        
        solve();
    }
return 0;
}