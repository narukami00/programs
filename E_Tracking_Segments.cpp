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

bool isbut(vector<int>&presum,int l,int r){
    int one=presum[r]-(l>1?presum[l-1]:0);
    int zero= (r-l+1)-one;
    return one>zero;
}

bool poss(vector<int>& arr, int n, vector<pair<int,int>>seg,int mid){
    vector<int> a(n+2,0);
    for(int i=1;i<=mid;i++){
        a[arr[i]]=1;
    }
    vector<int> presum(n+2,0);
    presum[1]=a[1];
    for(int i=2;i<=n;i++){
        presum[i]=presum[i-1]+a[i];
    }
    for(auto &it : seg){
        if(isbut(presum,it.first,it.second)) return true;
    }
    return false;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> seg(m+1);
        for(int i=1;i<=m;i++) cin>>seg[i].first>>seg[i].second;

        int q;cin>>q;
        vector<int> arr(q+1);
        for(int i=1;i<=q;i++) cin>>arr[i];

        int l=1,r=q,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(poss(arr,n,seg,mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }

        cout<<ans<<endl;
    }
return 0;
}