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
        int n,m,k;
        cin>>n>>m>>k;

        int dis=n+m-2;
        if(k<dis || k%2!=dis%2){
            no;continue;
        }

        yes;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                cout<<(j%2?'R':'B')<<sp;
            }cout<<endl;
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                cout<<(((i+m)%2 && j==m-1)?'R':'B')<<sp;
            }cout<<endl;
        }
    }
return 0;
}