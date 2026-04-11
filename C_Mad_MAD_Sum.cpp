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
        vector<int>a(n);
        cin>>a;

        int ans=0;
        int op=2;
        while(op--){
            vector<int>b(n);
            map<int,int>freq;
            int mx=0;
            for(int i=0;i<n;i++){
                freq[a[i]]++;
                ans+=a[i];
                if(freq[a[i]]>=2)mx=max(mx,a[i]);
                b[i]=mx;
            }
            for(int i=0;i<n;i++)a[i]=b[i];
        }
        int con=1;
        for(int i=n-1;i>=0;i--){
            ans+=a[i]*con;
            con++;
        }

        cout<<ans<<endl;
    }
return 0;
}