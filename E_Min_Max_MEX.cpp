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
#define sz(x) x.size()
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

bool pos(vector<int>&arr,int k,int x){
    if(x==0) return true;

    int need=x;
    vector<bool>f(x,0);
    int cnt=0;

    for(int it:arr){
        if(it<x && !f[it]){
            f[it]=1;
            need--;
        }
        if(need==0){
            cnt++;
            need=x;
            for(auto i:f)i=0;
        }
    }
    
    if(cnt>=k) return true;
    else return false;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        cin>>arr;

        int m=-1;
        vector<bool> f(n+2,0);
        for(int it:arr){
            if(it<n+2)f[it]=1;
        }
        for(int i=0;i<f.size();i++){
            if(!f[i]){m=i;}
        }
        if(m==-1)m=n+1;

        int l=0,r=m,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(arr,k,mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        cout<<ans<<endl;
    }
return 0;
}