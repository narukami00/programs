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
        string s;
        cin>>s;
        bool f=0;
        int indx=-1;
        for(int i=1;i<sz(s)-1;i++){
            if(s[i]=='a'){
                indx=i;
                break;
            }
        }

        if(indx!=-1){
            for(int i=0;i<indx;i++)cout<<s[i];
            cout<<" a ";
            for(int i=indx+1;i<sz(s);i++)cout<<s[i];
        }else{
            cout<<s[0]<<sp;
            for(int i=1;i<sz(s)-1;i++)cout<<s[i];
            cout<<sp<<s[sz(s)-1];
        }
        cout<<endl;
    }
return 0;
}