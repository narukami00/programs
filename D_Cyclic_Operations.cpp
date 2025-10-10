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
        vector<int>b(n);
        cin>>b;
        vector<int>vis(n,0);
        
        if(k==1){
            bool f=1;
            for(int i=0;i<n;i++)if(b[i]!=i+1)f=0;
            if(f)yes;else no;
            continue;
        }

        vector<int>num(n);
        int f=1;
        int x=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int idx=i;
                int temp=0;
                while(!vis[idx]){
                    vis[idx]=x;
                    num[idx]=temp++;
                    idx=b[idx]-1;
                }
                if(vis[idx]!=x){
                    x++;
                    continue;
                }
                if(temp-num[idx]!=k){
                    f=0;
                    break;
                }
                x++;
            }
        }

        if(f)yes;
        else no;
    }
return 0;
}