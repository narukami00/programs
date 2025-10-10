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

const int z=1e6+10;
int a[z],s[z],pre[z][31];

int32_t main(){
    Flashyy
    tc
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        s[n+1]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                if((1ll<<j) <= a[i-1]){
                    pre[i][j]=i-1;
                }else{
                    pre[i][j]=pre[i-1][j];
                }
            }
        }
        for(int i=n;i>=1;i--)s[i]=s[i+1]^a[i];
        for(int i=1;i<=q;i++){
            int x;
            cin>>x;
            int cur=x,next=n;
            while(cur>=a[next] && next>=1){
                cur=x^s[next];
                next=pre[next][(int)log2(cur)];
                cur=x^s[next+1];
            }
            cout<<n-next<<endl;
        }
    }
return 0;
}