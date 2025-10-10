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
    tc
    {
        int n;
        cin>>n;
        vector<int>deg(n+1,0);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }

        string s;
        cin>>s;
        int zero=0,one=0,qus=0;
        for(int v=2;v<=n;v++){
            if(deg[v]==1){
                if(s[v-1]=='1')one++;
                else if(s[v-1]=='0')zero++;
                else qus++;
            }
        }
        
        int total=0;
        for(char c:s)if(c=='?')total++;
        int dontcare=total-qus-(s[0]=='?'?1:0);

        bool iris=dontcare%2;
        int ans=0;

        if(s[0]=='1')ans=zero+((qus+1)/2);
        else if(s[0]=='0')ans=one+((qus+1)/2);
        else ans=max(one,zero)+ ((qus+(one==zero?iris:0))/2);

        cout<<ans<<endl;
    }
return 0;
}