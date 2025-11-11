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

int dr[]={-2,-1,1,2,2,1,-1,-2};
int dc[]={1,2,2,1,-1,-2,-2,-1};

int n, s_row,s_col;
int board[55][55];

bool val(int r, int c){
    return (r>=1 && r<=n && c>=1 && c<=n && board[r][c]==0);
}

int deg(int r, int c){
    int cnt=0;
    for(int i=0;i<8;i++){
        int nr=r+dr[i],nc=c+dc[i];
        if(val(nr,nc))cnt++;
    }
    return cnt;
}

bool knightsTour(int r,int c){
    board[r][c]=1;
    for(int m=2;m<=n*n;m++){
        vector<pair<int,int>>ops;

        for(int i=0;i<8;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(val(nr,nc))ops.pb({deg(nr,nc),i});
        }

        if(ops.empty())return false;

        sort(all(ops));

        int i=ops[0].s;
        r+=dr[i];
        c+=dc[i];
        board[r][c]=m;
    }
    return true;
}

int32_t main(){
    Flashyy
    //tc
    bool first=1;
    while(cin>>n>>s_row>>s_col)
    {
        if(!first)cout<<endl;
        first=0;
        if(n<=5){cout<<"No Circuit Tour.\n";continue;}

        memset(board,0,sizeof(board));
        knightsTour(s_row,s_col);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<setw(5)<<board[i][j];
            }
            cout<<endl;
        }

    }
return 0;
}