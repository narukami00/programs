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
        string s;
        cin>>s;

        if(s[0]==s[n-1]){
            if(s[0]=='A')cout<<"Alice\n";
            else cout<<"Bob\n";
            continue;
        }

        if(n==2){
            if(s[0]=='A')cout<<"Alice\n";
            else cout<<"Bob\n";
            continue;
        }

        vector<int>a,b;
        for(int i=0;i<n;i++){
            if(s[i]=='A')a.pb(i+1);
            else b.pb(i+1);
        }

        bool al=0;
        for(int i=0;i<sz(a);i++){
            int cur=a[i];
            bool f=0;
            for(int j=0;j<sz(b);j++){
                if((b[j]>cur && (b[j]!=n || cur!=1)) || (b[j]==1 && cur==n)){
                    f=1;
                    break;
                }
            }
            if(f==0){
                al=1;
                break;
            }
        }

        if(al)cout<<"Alice\n";
        else cout<<"Bob\n";

    }
return 0;
}