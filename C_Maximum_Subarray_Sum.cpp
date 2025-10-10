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

int INF=-1e13;

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>arr(n);
        cin>>arr;

        int pos=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                pos=i;
                arr[i]=INF;
            }
        }

        int mx=0,cur=0;
        for(int i=0;i<n;i++){
            cur=max(cur+arr[i],arr[i]);
            mx=max(mx,cur);
        }

        if(mx>k || (mx!=k && pos==-1)){
            no;
            continue;
        }

        if(pos!=-1){
            mx=0,cur=0;
            for(int i=pos+1;i<n;i++){
                cur+=arr[i];
                mx=max(mx,cur);
            }
            int left=mx;
            mx=0,cur=0;
            for(int i=pos-1;i>=0;i--){
                cur+=arr[i];
                mx=max(mx,cur);
            }
            int right=mx;
            arr[pos]=k-left-right;
        }

        yes;
        cout<<arr<<endl;
    }
return 0;
}