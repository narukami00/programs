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
        vector<int>a(n),b(n);
        cin>>a;cin>>b;
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    ans.pb({1,j+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(b[j]>b[j+1]){
                    swap(b[j],b[j+1]);
                    ans.pb({2,j+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                swap(a[i],b[i]);
                ans.pb({3,i+1});
            }
        }

        cout<<sz(ans)<<endl;
        for(auto it:ans)cout<<it.f<<sp<<it.s<<endl;
    }
return 0;
}