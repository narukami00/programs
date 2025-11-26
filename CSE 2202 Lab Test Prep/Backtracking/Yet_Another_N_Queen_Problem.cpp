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
int n;
vector<int>board;
bool solved=0;

bool isSafe(int row,int col,vector<int>&board){
    for(int i=1;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row)){
            return false;
        }
    }
    return true;
}

void solve(int row, vector<int>&board){
    if(solved)return;

    if(row>n){
        solved=1;
        for(int i=1;i<=n;i++){
            cout<<board[i]<<(i==n?"\n":" ");
        }
        return;
    }

    if(board[row]!=0){
        if(isSafe(row,board[row],board)){
            solve(row+1,board);
        }
        return;
    }

    for(int col=1;col<=n;col++){
        if(isSafe(row,col,board)){
            board[row]=col;
            solve(row+1,board);
            if(solved)return;
            board[row]=0;
        }
    }
}

int32_t main(){
    Flashyy
    while(1)
    {
        if(!(cin>>n))break;
        board.assign(n+1,0);
        for(int i=1;i<=n;i++)cin>>board[i];
        solved=0;
        solve(1,board);
    }
return 0;
}