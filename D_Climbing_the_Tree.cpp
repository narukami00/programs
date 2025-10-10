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

pair<int,int> rng(int a,int b,int n){
    if(n==1)return {1,a};
    int low=(n-2)*(a-b)+a+1;
    int high=(n-1)*(a-b)+a;
    return {low,high};
}

int days(int a,int b,int h){
    if(h<=a)return 1;
    h-=a;
    int d=(h+(a-b-1))/(a-b);
    return d+1;
}

int32_t main(){
    Flashyy
    tc
    {
        int q;
        cin>>q;
        vector<int>ans;
        int l=1,r=1e18;
        while(q--){
            int t;
            cin>>t;
            if(t==1){
                int a,b,n;
                cin>>a>>b>>n;
                auto [low,high]=rng(a,b,n);

                if(low>r || high<l){
                    ans.pb(0);
                }else{
                    l=max(l,low);
                    r=min(r,high);
                    ans.pb(1);
                }
            }else{
                int a,b;
                cin>>a>>b;
                int d1=days(a,b,l);
                int d2=days(a,b,r);
                if(d1==d2){
                    ans.pb(d1);
                }else{
                    ans.pb(-1);
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}