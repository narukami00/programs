#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);
#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;
typedef double dl;

int n;
const int mx = 500 + 3;
int ara[mx][mx];

int vis[mx][mx];

bool check(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        return true;
    }
    return false;
}

vector<pair<int, int>> nxt = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dropedTo(int i, int j)
{

    int mn = ara[i][j];
    pair<int,int> mnp;
    

    for (int ii = 0; ii < 4; ii++)
    {
        int x = i + nxt[ii].first;
        int y = j + nxt[ii].second;
        if (check(x, y))
        {
            if(ara[x][y]<mn){// equal er condition nai
            ///surroundings e jeuta sob theke kom oy ta te jabo
                mn=ara[x][y];
                mnp.first=x;
                mnp.second=y;
            }
        }
    }
    if(mn!=ara[i][j]){
        //minimum paichi
        if(vis[mnp.first][mnp.second]!=0){
            //means minimum jeikhan theke pabo oytay function age colche
            vis[i][j]=vis[mnp.first][mnp.second];
        }
        else{
            vis[i][j]=dropedTo(mnp.first,mnp.second);
        }
    }
    else{
        vis[i][j]=mn;//ara[i][j] i thakbe
    }
    return vis[i][j];//ekdom last mn jeita paibo oyta set hoye jabe
    // main array te set korle problem hoito
    // like room 14 upto 2 temp reach korte pare
    // pore any adjacant room 7 , 14 temp cross kore felbe 2 set howyar karone

}

void solve()
{

    cin >> n;
    // int ara[n][n];
    // int vis[n][n];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         vis[i][j] = 0;
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ara[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0){
                dropedTo(i,j);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int q;
    cin>>q;
    while(q--){
        int i,j;
        cin>>i>>j;//1 indexing
        cout<<vis[i-1][j-1]<<endl;// zero indexing e calculate korte
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}


//possible minimum
// int dropedTo(int i, int j)
// {

//     int mn = ara[i][j];

//     for (int ii = 0; ii < 4; ii++)//i become ambiguous
//     {
//         int x = i + nxt[ii].first;
//         int y = j + nxt[ii].second;
//         if (check(x, y))
//         {
//             if (ara[x][y] < ara[i][j])
//             {
//                 // min=ara[x][y];
//                 // min=
//                 if (vis[x][y] != 0)
//                 {
//                     mn = min(mn, vis[x][y]);
//                 }
//                 else
//                 {
//                     mn = min(mn, dropedTo(x, y));
//                 }
//             }
//         }
//     }
//     return vis[i][j] = mn; // ekdom last mn jeita paibo oyta set hoye jabe
//     // main array te set korle problem hoito
//     // like room 14 upto 2 temp reach korte pare
//     // pore any adjacant room 7 , 14 temp cross kore felbe 2 set howyar karone
// }