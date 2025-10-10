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

int getval(int x,int y,int r,int c,int m,int o){
    if(m==1){
        if(x==r && y==c) return o+1;
        if(x==r+1 && y==c+1) return o+2;
        if(x==r+1 && y==c) return o+3;
        if(x==r && y==c+1) return o+4;
    }
    int side=1ll<<(m-1);
    int cell=1ll<<(2*(m-1));

    if(x>=r && x<r+side && y>=c && y<c+side){return getval(x,y,r,c,m-1,o);}
    else if(x>=r+side && x<r+2*side && y>=c+side && y<c+2*side){return getval(x,y,r+side,c+side,m-1,o+cell);}
    else if(x>=r+side && x<r+2*side && y>=c && y<c+side){return getval(x,y,r+side,c,m-1,o+2*cell);}
    else {return getval(x,y,r,c+side,m-1,o+3*cell);}
}

void getqd(int d,int r,int c,int m,int o,int &x,int &y){
    if(m==1){
        if(d==o+1){x=r;y=c;return;}
        if(d==o+2){x=r+1;y=c+1;return;}
        if(d==o+3){x=r+1;y=c;return;}
        if(d==o+4){x=r;y=c+1;return;}
    }
    int side=1ll<<(m-1);
    int cell=1ll<<(2*(m-1));

    if(d<=o+cell) getqd(d,r,c,m-1,o,x,y);
    else if(d<=o+2*cell) getqd(d,r+side,c+side,m-1,o+cell,x,y);
    else if(d<=o+3*cell) getqd(d,r+side,c,m-1,o+2*cell,x,y);
    else getqd(d,r,c+side,m-1,o+3*cell,x,y);
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        int q;
        cin>>q;
        while(q--){
            string s;
            cin>>s;
            if(s=="->"){
                int x,y;
                cin>>x>>y;
                int ans=getval(x,y,1,1,n,0ll);
                cout<<ans<<endl;
            }else if(s=="<-"){
                int d;
                cin>>d;
                int x,y;
                getqd(d,1,1,n,0ll,x,y);
                cout<<x<<sp<<y<<endl;
            }
        }
    }
return 0;
}