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
        int a,b,c;
        cin>>a>>b>>c;
        if(c!=a+1){
            cout<<-1<<endl;
            continue;
        }
        if(a+b+c==1){
            cout<<0<<endl;
            continue;
        }
        int cur=1,next=0,res=1;
        for(int i=0;i<a+b;i++){
            if(!cur){
                swap(next,cur);res++;
            }cur--,next++;
            if(i<a)next++;
        }
        cout<<res<<endl;
    }
return 0;
}

//math -> b/c+ceil(log2(c+b%c))