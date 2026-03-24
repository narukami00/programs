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
    //Flashyy
    tc
    {
        int n;
        cin>>n;
        int sum=(n*(n+1))/2;

        cout<<"2 "<<"1 "<<n<<endl;
        int nsum;cin>>nsum;
        int diff=nsum-sum;

        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            cout<<"1 "<<1<<" "<<mid<<endl;
            int x;cin>>x;
            cout<<"2 "<<1<<" "<<mid<<endl;
            int y;cin>>y;

            if(y>x)r=mid;
            else l=mid+1;
        }

        cout<<"! "<<l<<" "<<l+diff-1<<endl;
    }
return 0;
}