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
        int n,x;
        cin>>n>>x;
        int ans=0;

        if(n-x>0){
            for(int i=1;i<=sqrt(n-x);i++){
                if((n-x)%i==0){
                    int d1=i;
                    int d2=(n-x)/d1;
                    if(d1%2==0 && d1>=2*(x-1))ans++;
                    if(d2!=d1 && d2%2==0 && d2>=2*(x-1))ans++;
                }
            }
        }

        if(x>=2 && n+x-2>0){
            for(int i=1;i<=sqrt(n+x-2);i++){
                if((n+x-2)%i==0){
                    int d1=i;
                    int d2=(n+x-2)/d1;
                    if(d1%2==0 && d1>2*(x-1))ans++;
                    if(d2!=d1 && d2%2==0 && d2>2*(x-1))ans++;
                }
            }
        }
        
        cout<<ans<<endl;
    }
return 0;
}