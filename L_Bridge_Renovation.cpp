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
    //tc
    {
        int n;
        cin>>n;
        int ans=0;

        if(n==1){
            cout<<2<<endl;
            return 0;
        }

        if(n%2==0){
            int t1=n,t2=n,t3=n;
            ans=t1/2;
            t2-=(t1/2);
            ans+=(t2/3);
            if(t2%3==1){
                ans++;
                t3--;
            }else if(t2%3==2)ans++;
            ans+=((t3+1)/2);
        }else{
            int t1=n,t2=n,t3=n;
            ans=t1/2 +1;
            t2-=(t1/2)+2;
            ans+=(t2/3);
            if(t2%3==1){
                ans++;
                t3--;
            }else if(t2%3==2)ans++;
            ans+=((t3+1)/2);
        }
        cout<<ans<<endl;
    }
return 0;
}