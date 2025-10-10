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
    int cur=0;
    int mat[256][256];
    for(int i=0;i<256;i+=2){
        for(int j=0;j<256;j+=2){
            mat[i][j]=cur;
            mat[i][j+1]=cur+1;
            mat[i+1][j]=cur+2;
            mat[i+1][j+1]=cur+3;
            cur+=4;
        }
    }
    tc
    {
        int n,m;
        cin>>n>>m;
        cout<<n*m<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<mat[i][j]<<sp;
            }cout<<endl;
        }cout<<endl;
    }
return 0;
}