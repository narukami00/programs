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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>arr(n,vector<int>(m));
        int mx=0,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                mx=max(mx,arr[i][j]);
            }
        }
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==mx){
                    row[i]++;
                    col[j]++;
                    cnt++;
                }
            }
        }
        bool f=0;
        for(int i=0;i<n && !f;i++){
            for(int j=0;j<m;j++){
                int temp=row[i]+col[j]-(arr[i][j]==mx);
                if(temp==cnt){
                    f=1;
                    break;
                }
            }
        }
        if(f)mx--;
        cout<<mx<<endl;
    }
return 0;
}