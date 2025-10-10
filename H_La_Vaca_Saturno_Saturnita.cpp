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
        cout << it << endl;
    return ostream;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,q;
        cin>>n>>q;
        vector<int>a(n+1);
        map<int,vector<int>>pos;
        map<int,int>ptr;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]].pb(i);
            ptr[a[i]]=0;
        }
        vector<array<int,4>>query(q);
        int cnt=0;
        for(auto &[l,r,v,i]:query){
            cin>>v>>l>>r;
            i=cnt++;
        }
        vector<int>ans(q);
        sort(all(query));
        int prevL=1;
        for(auto [l,r,v,idx]:query){
            for(int j=prevL;j<l;j++){
                ptr[a[j]]++;
            }
            prevL=l;
            vector<pair<int,int>>fact;
            for(int i=1;i*i<=v;i++){
                if(v%i==0){
                    int temp=v/i;
                    if(!(sz(pos[temp])==0 || ptr[temp]>=sz(pos[temp]) || pos[temp][ptr[temp]]>r || temp==1)){
                        fact.pb({pos[temp][ptr[temp]],temp});
                    }
                    int temp2=i;
                    if(temp2==temp)continue;
                    if(!(sz(pos[temp2])==0 || ptr[temp2]>=sz(pos[temp2]) || pos[temp2][ptr[temp2]]>r || temp2==1)){
                        fact.pb({pos[temp2][ptr[temp2]],temp2});
                    }
                }
            }
            sort(all(fact));
            int r1=l;
            int anss=0;
            for(auto [indx,val]:fact){
                int r2=indx-r1;
                anss+=v*r2;
                while(v%val==0){
                    v/=val;
                }
                r1=indx;
            }
            if(fact.empty())anss=v*(r-l+1);
            else anss+=v*(r-r1+1);
            ans[idx]=anss;
        }

        cout<<ans;
    }
return 0;
}