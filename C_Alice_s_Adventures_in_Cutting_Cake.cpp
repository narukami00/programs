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
        int n,m,v;
        cin>>n>>m>>v;

        vector<int> arr(n+1);
        vector<int> pre(n+1);
        vector<int> posl(n+1);
        vector<int> posr(n+1);

        pre[0]=0;
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
            pre[i]=arr[i]+pre[i-1];
        }

        int s1=0,s2=0;

        for(int i=1,j=0;i<=n;i++){
            if(pre[i]-pre[j]>=v)posl[++s1]=j=i;
        }

        posr[0]=n+1;
        for(int i=n,j=n+1;i>0;i--){
            if(pre[j-1]-pre[i-1]>=v)posr[++s2]=j=i;
        }

        if(s1<m){
            cout<<-1<<endl;
        }else{
            int ans=-1;
            for(int i=0;i<=m;i++){
                if(posl[i]<posr[m-i]) ans=max(ans,pre[posr[m-i]-1]-pre[posl[i]]);
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}
