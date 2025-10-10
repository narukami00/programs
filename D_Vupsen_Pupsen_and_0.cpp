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

        int tn=n;
        if(n%2!=0)tn-=3;
        vector<int>ans;

        for(int i=0;i<tn;i+=2){
            int one=arr[i];
            int two=arr[i+1];
            ans.pb(two);
            ans.pb(-one);
        }

        if(n%2!=0){
            int a=arr[n-3];
            int b=arr[n-2];
            int c=arr[n-1];

            if(a==b && b==c){
                ans.pb(1);
                ans.pb(-2);
                ans.pb(1);
            }else if(a==b){
                ans.pb(c);
                ans.pb(c);
                ans.pb(-2*a);
            }else if(b==c){
                ans.pb(-2*b);
                ans.pb(a);
                ans.pb(a);
            }else if(a==c){
                ans.pb(b);
                ans.pb(-2*a);
                ans.pb(b);
            }else{
                ans.pb(b-c);
                ans.pb(c-a);
                ans.pb(a-b);
            }
        }
        
        cout<<ans<<endl;
    }
return 0;
}