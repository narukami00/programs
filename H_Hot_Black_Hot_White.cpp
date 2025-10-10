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
        vector<int>arr(n);
        cin>>arr;
        vector<char>ans(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]%3==0){
                cnt++;
                if(cnt<=n/2)ans[i]='0';
                if(cnt>n/2)ans[i]='1';
            }
        }

        int z=0;
        if(cnt<=n/2){
            int rem=n/2-cnt;
            for(int i=0;i<n;i++){
                if(arr[i]%3!=0){
                    if(rem>0){
                        ans[i]='0';
                        rem--;
                    }else{
                        ans[i]='1';
                    }
                }
            }
        }

        if(cnt>n/2){
            z=2;
            for(int i=0;i<n;i++){
                if(arr[i]%3!=0){
                    ans[i]='1';
                }
            }
        }
        
        cout<<z<<endl;
        cout<<ans<<endl;
    }
return 0;
}