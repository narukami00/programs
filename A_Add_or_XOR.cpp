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
        int a,b,x,y;
        cin>>a>>b>>x>>y;

        vector<int>ans(205,LLONG_MAX);
        queue<int>q;
        ans[a]=0;
        q.push(a);

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            if(cur+1<205 && ans[cur+1]>ans[cur]+x){
                ans[cur+1]=ans[cur]+x;
                q.push(cur+1);
            }

            int temp=cur^1;
            if(temp<205 && ans[temp]>ans[cur]+y){
                ans[temp]=ans[cur]+y;
                q.push(temp);
            }
        }

        if(ans[b]==LLONG_MAX)cout<<-1<<endl;
        else cout<<ans[b]<<endl;
    }
return 0;
}