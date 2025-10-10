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
        int n,l;
        cin>>n>>l;
        vector<pair<int,int>>msg(n);
        for(auto &m:msg)cin>>m.f>>m.s;
        sort(all(msg),[&](auto &x,auto &y){return x.s<y.s;});

        auto pos=[&](int k)->bool{
            if(k==0) return true;
            for(int i=0;i+k-1<n;i++){
                priority_queue<int>pq;
                int sum=0;
                for(int j=i;j<n;j++){
                    int a=msg[j].f;
                    pq.push(a);
                    sum+=a;
                    if(sz(pq)>k){
                        sum-=pq.top();
                        pq.pop();
                    }
                    if(j-i+1>=k && sz(pq)==k){
                        int span=msg[j].s-msg[i].s;
                        if(sum+span<=l){
                            return true;
                        }
                    }
                }
            }
            return false;
        };

        int left=0,right=n,ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(pos(mid)){
                ans=mid;
                left=mid+1;
            }else right=mid-1;
        }
        cout<<ans<<endl;
    }
return 0;
}