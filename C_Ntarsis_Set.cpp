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
        vector<int>arr(n);
        map<int,int>cnt;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            cnt[arr[i]]++;
        }

        if(arr[0]!=1){
            cout<<1<<endl;
            continue;
        }

        int mex=1;
        while(cnt[mex])mex++;

        int cur=mex,days=1,best=n;
        
        for(int i=mex-1;i<n;i++){
            int len=i;
            int l=cur,r=arr[i]-1;
            int num=(r-l)/len;
            if(num+days<=k){
                days+=num;
                cur+=num*len;
            }else{
                best=len;
                break;
            }
        }
        
        cur+=best*(k-days);
        cout<<cur<<endl;
    }
return 0;
}