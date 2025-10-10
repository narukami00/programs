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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(m));
        vector<int> sums(n,0);
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;cin>>x;arr[i][j]=x;
                sums[i]+=x;
            }total+=sums[i];
        }
        if(total%n!=0){
            cout<<-1<<endl;
            continue;
        }
        int avg=total/n;
        vector<tuple<int,int,int>>ops;
        for(int j=0;j<m;j++){
            vector<int>have,need;
            for(int i=0;i<n;i++){
                if(arr[i][j]==1 && sums[i]>avg)have.pb(i);
                if(arr[i][j]==0 && sums[i]<avg)need.pb(i);
            }
            int k=min(sz(have),sz(need));
            for(int i=0;i<k;i++){
                int i1=have[i],i2=need[i];
                arr[i1][j]=0;arr[i2][j]=1;
                sums[i1]--;sums[i2]++;
                ops.pb({i1+1,i2+1,j+1});
            }
        }
        cout<<sz(ops)<<endl;
        for(auto [x,y,z]:ops)cout<<x<<sp<<y<<sp<<z<<endl;
    }
return 0;
}