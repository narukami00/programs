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

int F(vector<int>& prefix,int y){
    int n=prefix.size()-1;
    for(int i=1;i<=n;i++){
        if(y+prefix[i]==0) return i;
    }
    return -1;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,x,k;
        cin>>n>>x>>k;
        string s;
        cin>>s;
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            if(s[i]=='R') prefix[i+1]=prefix[i]+1;
            else prefix[i+1]=prefix[i]-1;
        }

        int time1=F(prefix,x);

        if(time1==-1 || time1>k){
            cout<<0<<endl;
            continue;
        }

        int reset=1;
        k-=time1;

        int time2=F(prefix,0);
        if(time2==-1){
            cout<<reset<<endl;
        }else{
            reset+=(k/time2);
            cout<<reset<<endl;
        }
    }
return 0;
}