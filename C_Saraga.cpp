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
        string s1,s2;
        cin>>s1>>s2;
        int n1=sz(s1);
        int n2=sz(s2);
        map<char,int>mp;
        for(int i=1;i<n1;i++){
            if(!mp[s1[i]])mp[s1[i]]=i;
        }

        int mn=LLONG_MAX;
        bool f=0;
        char ch;
        int indx;
        for(int i=n2-2;i>=0;i--){
            if(mp[s2[i]] && mp[s2[i]]+n2-i<mn){
                f=1;
                mn=mp[s2[i]]+n2-i;
                ch=s2[i];
                indx=i;
            }
        }

        if(f){
            for(int i=0;i<mp[ch];i++)cout<<s1[i];
            for(int i=indx;i<n2;i++)cout<<s2[i];
        }else cout<<"-1";
    }
return 0;
}