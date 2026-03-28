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

        for(int k=0;k<=7;k++){
            int m=n-k;
            if(m<0)break;
            string s=to_string(m);

            if(s.find('7')!=string::npos){
                cout<<k<<endl;
                break;
            }

            s="0"+s;
            bool f=0;

            for(int i=0;i<sz(s);i++){
                int dig=s[i]-'0';
                int need=(17-dig)%10;
                if(need<=k){
                    f=1;
                    break;
                }
            }

            if(f){
                cout<<k<<endl;
                break;
            }
        }
    }
return 0;
}