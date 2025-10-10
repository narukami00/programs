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

struct SP{
    vector<vector<int>>st;
    vector<int>logval;
    int n;
    bool ismx;

    SP(vector<int>&arr,bool ismxq){
        ismx=ismxq;
        n=sz(arr);
        logval.resize(n+1);
        for(int i=2;i<=n;i++){
            logval[i]=logval[i/2]+1;
        }
        int k=logval[n]+1;
        st.assign(k,vector<int>(n));
        st[0]=arr;
        for(int tk=1;tk<k;tk++){
            for(int i=0;i+(1<<tk)<=n;i++){
                if(ismx) st[tk][i]=max(st[tk-1][i],st[tk-1][i+(1<<(tk-1))]);
                else st[tk][i]=min(st[tk-1][i],st[tk-1][i+(1<<(tk-1))]);
            }
        }
    }

    int query(int l,int r){
        int j=logval[r-l+1];
        if(ismx) return max(st[j][l],st[j][r-(1<<j)+1]);
        else return min(st[j][l],st[j][r-(1<<j)+1]);
    }
};

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        cin>>a;
        cin>>b;

        bool f=1;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                f=0;
                break;
            }
        }

        if(!f){
            no;continue;
        }

        SP stmx(a,1);
        SP stmn(b,0);

        vector<vector<int>>pos(n+1);
        for(int i=0;i<n;i++){
            pos[a[i]].push_back(i);
        }

        for(int i=0;i<n && f;i++){
            if(a[i]==b[i])continue;

            int cur=b[i];
            bool val=0;

            if(pos[cur].empty()){
                f=0;
                break;
            }

            int indx=lower_bound(all(pos[cur]),i)-pos[cur].begin();

            if(indx>0){
                int j=pos[cur][indx-1];
                int l=min(i,j),r=max(i,j);
                if(stmx.query(l,r)<=cur && stmn.query(l,r)>=cur)val=1;
            }

            if(!val && indx<sz(pos[cur])){
                int j=pos[cur][indx];
                int l=min(i,j),r=max(i,j);
                if(stmx.query(l,r)<=cur && stmn.query(l,r)>=cur)val=1;
            }

            if(!val){
                f=0;
                break;
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}