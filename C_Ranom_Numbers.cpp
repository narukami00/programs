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
int val[]={1,10,100,1000,10000};
int32_t main(){
    Flashyy
    tc
    {
        string s;
        cin>>s;
        for(char &c:s)c-='A';
        reverse(all(s));
        int best=LLONG_MIN;
        auto check=[&](int pos){
            if(pos==-1)return;
            for(char v=0;v<5;v++){
                swap(v,s[pos]);
                int x=0,sum=0;
                for(char c:s){
                    if(c>=x){
                        sum+=val[c];
                        x=c;
                    }else sum-=val[c];
                }
                best=max(best,sum);
                swap(v,s[pos]);
            }
        };
        for(char i=0;i<5;i++){check(s.find_first_of(i)),check(s.find_last_of(i));}
        cout<<best<<endl;
    }
return 0;
}