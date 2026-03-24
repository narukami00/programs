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
        string s;
        cin>>s;
        int n=sz(s);
        vector<int>ps(n);
        ps[0]=0;
        for(int i=1;i<n;i++){
            int j=ps[i-1];
            while(j>0 && s[i]!=s[j])j=ps[j-1];
            if(s[i]==s[j])j++;
            ps[i]=j;
        }

        if(ps[n-1]*2>n){
            yes;
            cout<<s.substr(0,ps[n-1])<<endl;
        }else{
            no;
        }

    }
return 0;
}