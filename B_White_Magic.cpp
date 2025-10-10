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

bool fun(vector<int>arr){
    int n=sz(arr);
    vector<int>suf(n);
    set<int>missing;
    for(int i=0;i<=n;i++)missing.insert(i);
    for(int i=n-1;i>=1;i--){
        missing.erase(arr[i]);
        suf[i]=*missing.begin();
    }
    int mn=arr[0];
    for(int i=0;i<n-1;i++){
        mn=min(mn,arr[i]);
        if(mn<suf[i+1])return false;
    }
    return true;
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
        int cnt=0;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt++;
                if(!f){
                    temp.pb(arr[i]);
                }
                f=1;
            }else{
                temp.pb(arr[i]);
            }
        }
        if(cnt>0 && fun(temp)){
            cout<<n-cnt+1<<endl;
        }else cout<<n-cnt<<endl;
    }
return 0;
}