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
    tc
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=count(all(s),'1');
        if(cnt%2!=0 || s[0]!='1' || s[n-1]!='1'){
            no;
            continue;
        }

        vector<char> a(n),b(n);
        int seen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(seen<cnt/2){
                    a[i]=b[i]='(';
                }else{
                    a[i]=b[i]=')';
                }
                seen++;
            }
        }

        bool f=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(f==0){
                    a[i]='(';
                    b[i]=')';
                    f=1;
                }else{
                    a[i]=')';
                    b[i]='(';
                    f=0;
                }
            }
        }

        yes;
        cout<<a<<endl;
        cout<<b<<endl;
    }
return 0;
}