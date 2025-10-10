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
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int mx=0;
        char c;
        for(int i=0;i<n;i++){
            int t=mx;
            mx=max(mx,mp[s[i]]);
            if(mx!=t){
                c=s[i];
            }
        }
        int mn=LLONG_MAX;
        char cc;
        for(int i=0;i<n;i++){
            int t=mn;
            mn=min(mn,mp[s[i]]);
            if(mn!=t){
                cc=s[i];
            }
        }

        //cout<<c<<sp<<cc<<endl;
        for(int i=0;i<n;i++){
            if(s[i]==cc && s[i]!=c){
                s[i]=c;
                break;
            }
            else if(c==cc &&s[i]!=c){
                s[i]=c;
                break;
            }
        }

        cout<<s<<endl;

    }
return 0;
}