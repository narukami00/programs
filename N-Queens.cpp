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

class Solution {
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&lrow,vector<int>&udiag,vector<int>&ldiag,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(lrow[row]==0 && ldiag[row+col]==0 && udiag[n-1+col-row]==0){
                board[row][col]='Q';
                lrow[row]=1;
                ldiag[row+col]=1;
                udiag[n-1+col-row]=1;
                solve(col+1,board,ans,lrow,udiag,ldiag,n);
                board[row][col]='.';
                lrow[row]=0;
                ldiag[row+col]=0;
                udiag[n-1+col-row]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        vector<int>lrow(n,0),udiag(2*n-1,0),ldiag(2*n-1,0);
        solve(0,board,ans,lrow,udiag,ldiag,n);
        return ans;
    }
};

int32_t main(){
    Flashyy
    Solution sol;
    int n;
    cin >> n;
    vector<vector<string>> ans = sol.solveNQueens(n);
    for (const auto& board : ans) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}