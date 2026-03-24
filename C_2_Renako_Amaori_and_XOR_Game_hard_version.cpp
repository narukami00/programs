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
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
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

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        cin>>a>>b;

        int dif=0,bit=0,idx=0;
        for(int i=0;i<n;i++)dif^=a[i]^b[i];
        if(!dif)cout<<"Tie\n";
        else{
            for(int i=0;i<20;i++){
                if(dif&(1<<i)){
                    bit=i;
                }
            }
            for(int i=0;i<n;i++){
                if((a[i]^b[i])&(1<<bit)){
                    idx=i;
                }
            }
            if(idx&1)cout<<"Mai\n";
            else cout<<"Ajisai\n";
        }
    }
return 0;
}