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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+(s[i-1]=='('? 1:-1);
        }

        if(pre[n]!=2 && pre[n]!=-2){
            cout<<0<<endl;
            return 0;
        }

        vector<int>mnsuf(n+1,0);
        mnsuf[n]=pre[n];
        for(int i=n-1;i>=0;i--){
            mnsuf[i]=min(pre[i],mnsuf[i+1]);
        }

        int ans=0;
        if(pre[n]==2){
            int mn=0;
            for(int i=1;i<=n;i++){
                if(i>1)mn=min(mn,pre[i-1]);

                if(s[i-1]=='(' && mnsuf[i]>=2 && mn>=0)ans++;
            }
        }
        else{
            int mn=0;
            for(int i=1;i<=n;i++){
                if(i>1)mn=min(mn,pre[i-1]);

                if(s[i-1]==')' && mnsuf[i]>=-2 && mn>=0)ans++;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}