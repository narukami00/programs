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

const int mod=1e9+7;

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),pos(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            pos[a[i]]=i;
        }
        int ans=1;
        int l=pos[0],r=pos[0];
        int free=0;
        for(int x=1;x<n;x++){
            int p=pos[x];
            if(p<l){
                free+=(l-p-1);
                l=p;
            }else if(p>r){
                free+=(p-r-1);
                r=p;
            }else{
                ans=(ans*free)%mod;
                free--;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}