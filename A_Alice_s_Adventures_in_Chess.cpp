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
    tc
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        bool pos=0;
        int x=0,y=0;
        for(int j=0;j<100;j++){
            for(int i=0;i<s.size();i++){
                if(s[i]=='N') y++;
                else if(s[i]=='E') x++;
                else if (s[i]=='S') y--;
                else if(s[i]=='W') x--;

                if(x==a && y==b){
                    pos=1;
                    break;
                }
            }
        }
        
        if(pos)yes;
        else no;

    }
return 0;
}