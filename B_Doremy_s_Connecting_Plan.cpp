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
        int n,c;
        cin>>n>>c;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];

        int sum=arr[1];
        vector<pair<int,int>>res;
        for(int i=2;i<=n;i++)res.pb({i,arr[i]});

        sort(all(res),[c](pair<int,int>p1,pair<int,int>p2){
            return (c*p1.f-p1.s)<(c*p2.f-p2.s);
        });

        bool f=1;
        for(auto &p:res){
            int indx=p.f,ppl=p.s;
            if(sum<c*indx-ppl){
                f=0;
                break;
            }
            sum+=ppl;
        }
        if(f)yes;
        else no;
    }
return 0;
}