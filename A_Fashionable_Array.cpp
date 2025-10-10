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
        sort(all(arr));

        int fodd=n,lodd=-1,feven=n,leven=-1;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                feven=min(feven,i);
                leven=max(leven,i);
            }else{
                fodd=min(fodd,i);
                lodd=max(lodd,i);
            }
        }

        int best=0;
        if(leven>=feven)best=max(best,leven-feven+1);
        if(lodd>=fodd)best=max(best,lodd-fodd+1);
        cout<<n-best<<endl;
    }
return 0;
}