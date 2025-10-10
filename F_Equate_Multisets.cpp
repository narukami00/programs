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
        multiset<int>a,b;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            while(x%2==0)x/=2;
            a.insert(x);
        }
        for(int i=0;i<n;i++){
            int x;cin>>x;
            b.insert(x);
        }

        while(!b.empty()){
            int x=*b.rbegin();
            if(!a.count(x)){
                if(x==1)break;
                b.erase(b.find(x));
                b.insert(x/2);
            }else{
                b.erase(b.find(x));
                a.erase(a.find(x));
            }
        }

        if(b.empty())yes;
        else no;
    }
return 0;
}