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
        vector<int>ans(n);
        vector<tuple<int,int,int>>ev;
        for(int i=0;i<n;i++){
            int l,r,a,b;
            cin>>l>>r>>a>>b;
            ans[i]=b;
            ev.pb({b,1,i});
            ev.pb({l,-1,i});
        }
        int q;
        cin>>q;
        vector<int>qr(q);
        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            qr[i]=x;
            ev.pb({x,0,i});
        }
        sort(rall(ev));
        multiset<int>s;
        for(auto [x,type,idx]:ev){
            if(type==1){
                if(!s.empty())ans[idx]=*s.rbegin();
                s.insert(ans[idx]);
            }else if(type==0){
                if(!s.empty()){
                    qr[idx]=max(qr[idx],*s.rbegin());
                }
            }else{
                auto it=s.find(ans[idx]);
                if (it!=s.end())s.erase(it);
            }
        }
        cout<<qr<<endl;
    }
return 0;
}