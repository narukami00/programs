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
        vector<int>arr(n);
        cin>>arr;
        bool f=0;
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])<=1){
                f=1;
                break;
            }
        }

        if(f){
            cout<<0<<endl;
            continue;
        }

        int ans=n+1;
        for(int l=0;l<n;l++){
            int mn=LLONG_MAX,mx=LLONG_MIN;
            for(int r=l;r<n;r++){
                mn=min(mn,arr[r]);
                mx=max(mx,arr[r]);
                int dif=r-l;
                if(dif==0)continue;
                if(r+1<n){
                    if(max(mn,arr[r+1]-1) <= min(mx,arr[r+1]+1)){
                        ans=min(ans,dif);
                    }
                }
                if(l>0){
                    if(max(mn,arr[l-1]-1) <=  min(mx,arr[l-1]+1)){
                        ans=min(ans,dif);
                    }
                }
            }
        }

        if(ans<=n)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
return 0;
}