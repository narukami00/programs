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
#define sz(x) x.size()
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
    int f[10]={0};
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            for(int z=0;z<10;z++){
                int s=x+y+z;
                if(s<10)f[s]++;
            }
        }
    }
    tc
    {
        string s;
        cin>>s;
        int ans=1;
        for(char c: s){
            int d=c-'0';
            ans*=f[d];
        }
        cout<<ans<<endl;
    }
return 0;
}