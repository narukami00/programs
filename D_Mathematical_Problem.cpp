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

string fastmul(string &a,string &b){
    int n=sz(a),m=sz(b);
    vector<int>res(n+m,0);
    for(int i=n-1;i>=0;i--){
        int d1=a[i]-'0';
        for(int j=m-1;j>=0;j--){
            int d2=b[j]-'0';
            int sum=res[i+j+1]+d1*d2;
            res[i+j+1]=sum%10;
            res[i+j]+=sum/10;
        }
    }
    string ret;
    for(int it:res){
        if(!(ret.empty() && it==0)){
            ret.pb(it+'0');
        }
    }
    return ret.empty()?"0":ret;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;

        if(n==1){
            cout<<1<<endl;continue;
        }

        int k=(n-3)/2;
        vector<string>ans;
        for(int x=0;x<=k;x++){
            string r="1"+string(x,'0')+"3"+string(k-x,'0');
            ans.pb(fastmul(r,r));
        }
        for(int x=0;x<=k;x++){
            string r="3"+string(x,'0')+"1"+string(k-x,'0');
            ans.pb(fastmul(r,r));
        }
        string r="14"+string(k,'0');
        ans.pb(fastmul(r,r));

        for(string &s:ans)cout<<s<<endl;
    }
return 0;
}