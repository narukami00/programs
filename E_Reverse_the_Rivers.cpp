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
    //tc
    {
        int n,k,q;
        cin>>n>>k>>q;
        vector<vector<int>>col(k,vector<int>(n));
        for(int j=0;j<k;j++){
            cin>>col[j][0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                int x;
                cin>>x;
                col[j][i]=col[j][i-1]|x;
            }
        }

        while(q--){
            int m;
            cin>>m;
            int lb=0,ub=n;
            bool f=1;
            for(int p=0;p<m;p++){
                int r,c;
                char op;
                cin>>r>>op>>c;
                r-=1;
                if(op=='>'){
                    auto it=upper_bound(all(col[r]),c);
                    if(it==col[r].end())f=0;
                    else{
                        int indx=it-col[r].begin();
                        lb=max(lb,indx);
                    }
                }
                else if(op=='<'){
                    auto it=lower_bound(all(col[r]),c);
                    int indx=it-col[r].begin();
                    if(indx==0)f=0;
                    else ub=min(ub,indx);
                }
            }
            if(!f || lb>=ub)cout<<-1<<endl;
            else cout<<lb+1<<endl;
        }
    }
return 0;
}