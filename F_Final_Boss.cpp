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
        int hp,n;
        cin>>hp>>n;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;
        int cur=1;
        vector<int>a(n),c(n);
        cin>>a;
        cin>>c;
        for(int i=0;i<n;i++){
            hp-=a[i];
            pq.push({cur+c[i],i});
        }

        while(hp>0){
            auto [time,idx]=pq.top();
            pq.pop();
            cur=time;
            hp-=a[idx];
            pq.push({cur+c[idx],idx});
        }

        cout<<cur<<endl;
    }
return 0;
}