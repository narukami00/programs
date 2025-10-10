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
        int n;cin>>n;
        vector<int>arr(n);
        cin>>arr;

        vector<pair<int,int>>rng(n);
        int mn=LLONG_MAX,mx=0;
        for(int i=0;i<n;i++){
            int l=arr[i]+1;
            int r=arr[i]+(i+1);
            rng[i]={r,l};
            mn=min(mn,l);
            mx=max(mx,r);
        }
        
        sort(rall(rng));
        priority_queue<int>avl;
        vector<int>res;
        int indx=0,x=mx;

        while(x>=mn && (!avl.empty() || indx<n)){
            while(indx<n && rng[indx].f>=x){
                avl.push(rng[indx].s);
                indx++;
            }
            while(!avl.empty() && avl.top()>x){
                avl.pop();
            }
            if(!avl.empty()){
                avl.pop();
                res.pb(x);
                x--;
            }else{
                if(indx<n){
                    x=rng[indx].f;
                }else break;
            }
        }

        cout<<res<<endl;
    }
return 0;
}