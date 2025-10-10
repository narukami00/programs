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
        int n;cin>>n;
        map<int,int>freq;
        int mx=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            freq[x]++;
            if(x>mx)mx=x;
        }
        int ans=0;
        for(auto &p:freq){
            int x=p.f;
            int xcnt=p.s;
            if(xcnt>=3){
                ans+=xcnt*(xcnt-1)*(xcnt-2);
            }
            for(int b=2;;b++){
                int c2=x*b;
                int c3=c2*b;
                if(c3>1e9)break;
                if(freq.find(c2)!=freq.end() && freq.find(c3)!=freq.end()){
                    ans+=xcnt*freq[c2]*freq[c3];
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}