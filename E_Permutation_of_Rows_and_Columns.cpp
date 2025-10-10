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
#define sz(x) x.size()
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
        vector<vector<int>>a(n,vector<int>(m)),b(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>b[i][j];
            }
        }

        vector<pair<int,int>> posa(n*m+1),posb(n*m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                posa[a[i][j]]={i,j};
                posb[b[i][j]]={i,j};
            }
        }
        bool pos=1;
        vector<int>rmp(n,-1),cmp(m,-1);

        for(int i=1;i<=n*m;i++){
            int ra=posa[i].first,ca=posa[i].second;
            int rb=posb[i].first,cb=posb[i].second;

            if(rmp[ra]==-1)rmp[ra]=rb;
            else if(rmp[ra]!=rb) pos=0;

            if(cmp[ca]==-1)cmp[ca]=cb;
            else if(cmp[ca]!=cb) pos=0;
        }
        if(pos)yes;
        else no;
    }
return 0;
}