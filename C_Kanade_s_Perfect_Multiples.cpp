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
        int n,k;
        cin>>n>>k;
        set<int>s;
        for(int i=0;i<n;i++){int x;cin>>x;s.insert(x);}
        unordered_map<int,bool>mp;
        vector<int>ans;
        bool f=1;
        for(auto it:s){
            if(mp[it]==0){
                mp[it]=1;
                for(int i=2;it*i<=k;i++){
                    if(s.count(it*i)){
                        mp[it*i]=1;
                        s.erase(it*i);
                    }
                    else if(mp[it*i]==0){
                        f=0;break;
                    }
                }
                if(!f)break;
                ans.pb(it);
            }
        }

        if(f){
            cout<<ans.size()<<endl;
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
return 0;
}