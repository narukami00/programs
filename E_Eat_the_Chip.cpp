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
        int h,w;
        cin>>h>>w;
        vector<vector<int>> arr(2,vector<int>(2));
        cin>>arr[0][0]>>arr[0][1]>>arr[1][0]>>arr[1][1];

        if(arr[0][0]>=arr[1][0]){
            cout<<"Draw"<<endl;
            continue;
        }

        int winner=-1;
        int turn=0;

        while(arr[0][0]<arr[1][0]){
            int dis=arr[0][0]-arr[1][0];

            if(dis&1){
                if(arr[turn][1]>arr[!turn][1])arr[turn][1]--;
                if(arr[turn][1]<arr[!turn][1])arr[turn][1]++;
            }else{
                if(arr[turn][1]>arr[!turn][1] && arr[turn][1]+1<=w) arr[turn][1]++;
                if(arr[turn][1]<arr[!turn][1] && arr[turn][1]-1>=1) arr[turn][1]--;
            }
            arr[turn][0]+=turn?-1:1;

            if(arr[0]==arr[1]){
                winner=turn;
            }
            turn^=1;
        }
        if(winner==0)cout<<"Alice"<<endl;
        else if(winner==1)cout<<"Bob"<<endl;
        else cout<<"Draw"<<endl;
    }
return 0;
}