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
    //tc
    {
        vector<pair<int,int>>points;
        for(int i=0;i<3;i++){
            int x,y;
            cin>>x>>y;
            points.pb({x,y});
        }
        sort(all(points));
        if(points[0].f==points[1].f==points[2].f){
            cout<<1<<endl;
            cout<<points[0].f<<sp<<points[0].s<<sp<<points[2].f<<sp<<points[2].s<<endl;
            return 0;
        }
        if(points[0].s==points[1].s==points[2].s){
            cout<<1<<endl;
            cout<<points[0].f<<sp<<points[0].s<<sp<<points[2].f<<sp<<points[2].s<<endl;
            return 0;
        }
        vector<vector<int>>ans;
        int curx=points[0].f;
        int cury=points[0].s;
        int nextx=points[1].f;
        int nexty=points[1].s;
        int finalx=points[2].f;
        int finaly=points[2].s;

        if(curx==nextx){
            ans.pb({curx,cury,nextx,nexty});
        }
        else if(cury==nexty){
            ans.pb({curx,cury,nextx,nexty});
        }
        else{
            ans.pb({curx,cury,nextx,cury});
            ans.pb({nextx,cury,nextx,nexty});
        }

        if(cury>nexty){
            if(finaly<=cury && finaly>=nexty){
                ans.pb({nextx,finaly,finalx,finaly});
            }else if(finaly>cury){
                ans.pb({nextx,cury,nextx,finaly});
                ans.pb({nextx,finaly,finalx,finaly});
            }else if(finaly<nexty){
                ans.pb({nextx,nexty,nextx,finaly});
                ans.pb({nextx,finaly,finalx,finaly});
            }
        }else{
            if(finaly<=nexty && finaly>=cury){
                ans.pb({nextx,finaly,finalx,finaly});
            }else if(finaly>nexty){
                ans.pb({nextx,nexty,nextx,finaly});
                ans.pb({nextx,finaly,finalx,finaly});
            }else if(finaly<cury){
                ans.pb({nextx,cury,nextx,finaly});
                ans.pb({nextx,finaly,finalx,finaly});
            }
        }
        
        cout<<sz(ans)<<endl;
        for(int i=0;i<sz(ans);i++){
            for(auto x:ans[i])cout<<x<<sp;
            cout<<endl;
        }
    }
return 0;
}