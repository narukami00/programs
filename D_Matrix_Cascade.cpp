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
        vector<string>mat(n);
        cin>>mat;

        int ans=0;
        vector<vector<int>> flip(n,vector<int>(n,0));
        vector<vector<int>> op(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==1){
                    flip[i][j]^=flip[i-1][j];
                    if(j>0)flip[i][j]^=flip[i-1][j-1];
                    if(j<n-1)flip[i][j]^=flip[i-1][j+1];
                }else if(i>=2){
                    flip[i][j]^=flip[i-2][j];

                    if(j<n-1)flip[i][j]^=flip[i-1][j+1];
                    else flip[i][j]^=flip[i-2][j];
                    
                    if(j>0)flip[i][j]^=flip[i-1][j-1];
                    else flip[i][j]^=flip[i-2][j];

                    flip[i][j]^=op[i-1][j];
                }

                int cur=(flip[i][j]^(mat[i][j]-'0'))&1;
                if(cur==1){
                    ans++;
                    flip[i][j]^=1;
                    op[i][j]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}