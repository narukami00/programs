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
    //tc
    {
        int n,q;
        cin>>n>>q;
        vector<int>arr(n);
        cin>>arr;
        while(q--){
            int k;
            cin>>k;
            vector<int>temp=arr;
            int ans=0;
            for(int i=60;i>=0;i--){
                int sum=0;
                for(int j=0;j<n;j++){
                    if(temp[j] & (1ll<<i))continue;
                    int p=((temp[j]/(1ll<<i))+1)*(1ll<<i);
                    p+=ans^(p&ans);
                    sum+=p-temp[j];
                    if(sum>k)break;
                }
                if(sum>k)continue;
                for(int j=0;j<n;j++){
                    if(temp[j] & (1ll<<i))continue;
                    int p=((temp[j]/(1ll<<i))+1)*(1ll<<i);
                    p+=ans^(p&ans);
                    temp[j]=p;
                }
                ans+=(1ll<<i);
                k-=sum;
            }
            cout<<ans<<endl;
        }
    }
return 0;
}