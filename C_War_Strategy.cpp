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
        int n,m,k;
        cin>>n>>m>>k;
        if(k==1 || k==n){
            int ans=1;
            for(int i=n;i>=2;i--){
                int d=2*i-3;
                if(d<=m){
                    ans=i;
                    break;
                }
            }
            cout<<ans<<endl;
        }else{
            int ans=1;

            if(m>=1)ans=2;
            if(m>=2)ans=3;

            int big=max(k,n-k+1);
            int small=min(k-1,n-k);

            //cout<<big<<" "<<small<<endl;

            for(int i=big;i>=2;i--){
                int d1=2*i-3;
                
                if(d1<=m){
                    int rem=m-d1;
                    int d2=min({small,rem,i-1});
                    ans=max(ans,i+d2);
                }
            }

            cout<<ans<<endl;
        }

    }
return 0;
}