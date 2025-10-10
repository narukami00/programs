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
        vector<int>arr(n),per(n);
        cin>>arr;cin>>per;
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans=0,cnt=0;
        for(int i=n-1;i>=0;i--){
            pq.push(arr[per[i]-1]);
            while(sz(pq)>(i+1))pq.pop();
            if(sz(pq)==(i+1) && pq.top()*(i+1)>=ans){
                ans=pq.top()*(i+1);
                cnt=i+1;
            }
        }
        cout<<ans<<sp<<cnt<<endl;
    }
return 0;
}