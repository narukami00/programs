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
        int srt=0,nsrt=0,el=0;
        bool f=1;

        for(auto c:s){
            if(c=='+')el++;
            else if(c=='-'){
                el--;
                srt=min(srt,el);
                if(el<nsrt)nsrt=0;
            }else if(c=='1')srt=max(srt,el);
            else{
                if(el<=1){f=0;break;}
                if(nsrt==0 || nsrt>el)nsrt=el;
            }

            if(srt>=nsrt && nsrt!=0){
                f=0;break;
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}