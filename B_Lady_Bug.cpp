#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define eb emplace_back

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int cili(int a, int b) {
    if (a % b == 0) return (a / b);
    bool positive = !((a < 0) ^ (b < 0));
    return a / b + positive;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int n1=0,n2=0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(a[i]=='0')n2++;
                if(b[i]=='0')n1++;
            }else{
                if(a[i]=='0')n1++;
                if(b[i]=='0')n2++;
            }
        }

        if(n1>=(n+1)/2 && n2>=n/2)yes;
        else no;

    }
return 0;
}