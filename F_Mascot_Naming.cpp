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
        cout << it ;
    return ostream;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cin>>n;
        vector<string>arr(n);
        cin>>arr;
        string t;
        cin>>t;
        vector<string> ans(sz(t)+1);
        int mx=0;
        for(int i=0;i<n;i++){
            int pos=0;
            for(int j=0;j<sz(arr[i]);j++){
                if(arr[i][j]==t[pos]){
                    pos++;
                }else{
                    ans[pos]+=arr[i][j];
                }
            }
            mx=max(mx,pos);
            if(pos==sz(t)){
                mx=-1;
                break;
            }
        }
        if(mx==-1)no;
        else{
            yes;
            for(int i=0;i<mx;i++)cout<<ans[i]<<t[i];
            cout<<ans[mx]<<endl;
        }
    }
return 0;
}