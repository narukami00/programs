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
        int n,m;
        cin>>n>>m;
        m--;
        int x1,y1;
        cin>>x1>>y1;
        int win=0,vul1=0,vul2=0;
        map<pair<int,int>,int>mp;
        set<pair<int,int>>guess;
        int ans=0;
        while(m--){
            int x,y;
            cin>>x>>y;
            guess.insert({x,y});
            mp[{x,y}]++;
        }

        int wx,wy;
        for(auto it:guess){
            int x=it.f,y=it.s;
            int cnt=mp[{x,y}];
            if(x1!=x && y1!=y){
                int temp=win;
                win=max(win,cnt);
                if(win!=temp){
                    wx=x,wy=y;
                }
            }
            if(x1==x && y1!=y)vul1=max(vul1,cnt);
            if(x1!=x && y1==y)vul2=max(vul2,cnt);
        }

        if(win==0){
            cout<<max(vul1,vul2)+1<<endl;
            return 0;
        }

        int c1=0;
        for(auto it:guess){
            int x=it.f,y=it.s;
            int cnt=mp[{x,y}];
            if(((wx!=x)&&(wy==y))||((wx==x)&&(wy!=y)))c1+=cnt;
        }

        cout<<win+c1+1<<endl;
    }
return 0;
}