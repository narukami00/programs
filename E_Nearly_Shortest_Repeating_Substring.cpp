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

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        auto divs=getDivisors(n);
        string s;
        cin>>s;

        int ans=n;
        
        for(auto div:divs){
            bool pos=0;
            
            string s1=s.substr(0,div);
            int diff1=0;
            for(int i=0;i<n;i+=div){
                for(int j=0;j<div;j++){
                    if(s[i+j]!=s1[j])diff1++;
                }
                if(diff1>1)break;
            }
            if(diff1<=1)pos=1;

            if(!pos){
                string s2=s.substr(n-div,div);
                int diff2=0;
                for(int i=0;i<n;i+=div){
                    for(int j=0;j<div;j++){
                        if(s[i+j]!=s2[j])diff2++;
                    }
                    if(diff2>1)break;
                }
                if(diff2<=1)pos=1;
            }

            if(pos){
                ans=div;
                break;
            }
        }

        cout<<ans<<endl;
    }
return 0;
}