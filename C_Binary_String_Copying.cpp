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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;

        vector<int>zpos(n),opos(n);
        zpos[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0')zpos[i]=i;
            else if(i>0)zpos[i]=zpos[i-1];
        }

        opos[n-1]=n;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')opos[i]=i;
            else if(i+1<n)opos[i]=opos[i+1];
        }

        set<pair<int,int>>st;

        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(opos[l]>zpos[r]){
                st.insert({-1,-1});
            }else st.insert({opos[l],zpos[r]});
        }
        cout<<sz(st)<<endl;
    }
return 0;
}