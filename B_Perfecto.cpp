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
bool square(int x){
    if(x<0) return false;
    int l=0, r=5000000001;
    while(r-l>1){
        int mid=(l+r)/2;
        if(mid*mid<=x)l=mid;
        else r=mid;
    }
    if(l*l==x){
        return true;
    }
    return false;
}
int32_t main(){
    Flashyy
    tc
    {
        int n,f=3;
        cin>>n;
        if(square(n*(n+1)/2)) cout<<"-1"<<endl;
        else{
            vector<int> ans(n);
            ans[0]=2,ans[1]=1;
            for(int i=2;i<n;i++){
                ans[i]=i+1;
            }
            for(int i=2;i<n-1;i++){
                if(square(ans[i]+f)){
                    swap(ans[i],ans[i+1]);
                }
                f+=ans[i];
            }   
            cout<<ans<<endl;
        }
        
    }
return 0;
}