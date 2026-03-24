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
int INF=1e9+7;
int32_t main(){
    Flashyy
    tc
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        cin>>a>>b;
        sort(all(b));
        multiset<int>left,right;
        map<int,vector<int>>ll,rr;
        for(int i=0;i<n;i++){
            int x=a[i];
            int l=INF,r=INF;
            auto it = lower_bound(all(b), x);
            if(it!=b.begin()) {
                l=abs(*prev(it)-x);
            }
            if(it!=b.end()) {
                r=abs(*it-x);
            }

            left.insert(l);
            right.insert(r);
            ll[l].pb(r);
            rr[r].pb(l);
        }

        //for(auto x:left)cout<<x<<sp;cout<<endl;
        //for(auto x:right)cout<<x<<sp;cout<<endl;

        string op;
        cin>>op;
        int cur=0;
        int ans=n;
        for(int i=0;i<k;i++){
            if(op[i]=='L'){
                if(cur>0){cur--;cout<<ans<<sp;continue;}
                cur--;
                int ded=left.count(abs(cur));
                left.erase(abs(cur));
                if(ded>0){
                    for(auto x:ll[abs(cur)]){
                        auto it=right.find(x);
                        if(it!=right.end())right.erase(it);
                    }
                }
                ans-=ded;
                cout<<ans<<sp;
            }else{
                if(cur<0){cur++;cout<<ans<<sp;continue;}
                cur++;
                int ded=right.count(abs(cur));
                right.erase(abs(cur));
                if(ded>0){
                    for(auto x:rr[abs(cur)]){
                        auto it=left.find(x);
                        if(it!=left.end())left.erase(it);
                    }
                }
                ans-=ded;
                cout<<ans<<sp;
            }
        }
        cout<<endl;
    }
return 0;
}