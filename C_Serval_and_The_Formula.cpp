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

const int L=62;
const int inf=1ll<<60;
int dp[L+1][2][2];
bool vis[L+1][2][2];

int solve(int pos,int cx,int cy,int x,int y){
    if(pos==L){
        return (cx==0 && cy==0)?0ll:inf;
    }
    if(vis[pos][cx][cy]){
        return dp[pos][cx][cy];
    }
    vis[pos][cx][cy]=1;
    int ans=inf;
    int bx=(x>>pos)&1ll;
    int by=(y>>pos)&1ll;
    for(int k=0;k<2;k++){
        int sx=bx+k+cx;
        int a=sx&1;
        int ncx=sx>>1;

        int sy=by+k+cy;
        int b=sy&1;
        int ncy=sy>>1;

        if(a==1 && b==1) continue;

        int c=solve(pos+1,ncx,ncy,x,y);
        if(c==inf) continue;

        int t=(k<<pos)+c;
        ans=min(ans,t);
    }

    dp[pos][cx][cy]=ans;
    return ans;
}

int32_t main(){
    Flashyy
    tc
    {
        int x,y;
        cin>>x>>y;
        
        memset(vis,0,sizeof(vis));
        int ans=solve(0,0,0,x,y);

        if(ans>=inf)cout<<-1<<endl;
        else if(((x+ans)&(y+ans))==0)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
return 0;
}