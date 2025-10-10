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
        string s1,s2;
        cin>>s1>>s2;

        vector<int>zo1,zo2,oz1,oz2;
        int czo1=0,coz1=0,czo2=0,coz2=0;
        for(int i=0;i<n-1;i++){
            if(s1[i]=='0'&&s1[i+1]=='1'){czo1++;zo1.pb(i);}
            if(s1[i]=='1'&&s1[i+1]=='0'){coz1++;oz1.pb(i);}
            if(s2[i]=='0'&&s2[i+1]=='1'){czo2++;zo2.pb(i);}
            if(s2[i]=='1'&&s2[i+1]=='0'){coz2++;oz2.pb(i);}
        }

        if(czo1!=czo2 || coz1!=coz2 || s1[0]!=s2[0] || s1[n-1]!=s2[n-1]){
            cout<<-1<<endl;
            continue;
        }

        int ans=0;
        for(int i=0;i<sz(zo1);i++){
            ans+=abs(zo1[i]-zo2[i]);
        }
        for(int i=0;i<sz(oz1);i++){
            ans+=abs(oz1[i]-oz2[i]);
        }
        cout<<ans<<endl;
    }
return 0;
}