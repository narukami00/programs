#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            cout<<"? "<<l<<sp<<mid<<endl;
            int x,cnt=0;
            for(int i=0;i<mid-l+1;i++){
                cin>>x;
                if(x>=l && x<=mid)cnt++;
            }
            if(cnt%2==0)l=mid+1;
            else r=mid;
        }
        cout<<"! "<<l<<endl;
    }
return 0;
}