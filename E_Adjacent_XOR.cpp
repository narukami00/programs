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
        bool f=1;
        int prev=a[n-1];

        if(a[n-1]!=b[n-1]){
            no;continue;
        }

        for(int i=n-2;i>=0;i--){
            if(a[i]==b[i]){
                prev=a[i];
            }else if(b[i]==(a[i]^a[i+1])){
                prev=a[i]^a[i+1];
            }
            else if(b[i]==(a[i]^prev)){
                prev^=a[i];
            }else{
                f=0;break;
            }
        }

        if(f)yes;
        else no;
    }
return 0;
}