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
int f_row,f_col,sol_cnt,queens[9];

bool isSafe(int row, int col){
    for(int i=1;i<col;i++){
        if(queens[i]==row || abs(queens[i]-row)==abs(i-col)){
            return false;
        }
    }
    return true;
}

void solve(int col){
    if(col>8){
        if(queens[f_col]==f_row){
            cout<<setw(2)<<++sol_cnt<<"      ";
            for(int i=1;i<=8;i++){
                cout<<queens[i]<<(i==8?"\n":" ");
            }
        }
        return;
    }

    if(col==f_col){
        queens[col]=f_row;
        solve(col+1);
        return;
    }

    for(int row=1;row<=8;row++){
        if(isSafe(row,col)){
            queens[col]=row;
            solve(col+1);
        }
    }
}

int32_t main(){
    Flashyy
    tc
    {
        if(TC)cout<<endl;
        cin>>f_row>>f_col;
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n";
        sol_cnt=0;
        solve(1);
    }
return 0;
}