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
        string s;
        cin>>s;
        
        int digsum=0;
        for(char ch:s)digsum+= ch-'0';
        string res=s+"0";
        int i=n;
        int c=0;

        while(digsum>0 || c){
            int d1=(i>=0)?res[i]-'0':0;
            int d2=digsum%10;digsum/=10;
            int dif=d1-d2-c;
            if(dif<0){dif+=10;c=1;}
            else c=0;

            if(i>=0)res[i]=dif+'0';
            else res.insert(res.begin(),dif+'0');
            i--;
        }

        int indx=0;
        while(indx<sz(res) && res[indx]=='0')indx++;
        if(indx==sz(res))res="0";
        else res=res.substr(indx);

        string ans="";
        int rem=0;
        for(char ch:res){
            int cur=rem*10+(ch-'0');
            int d=cur/9;
            rem=cur%9;
            ans.pb(d+'0');
        }

        indx=0;
        while(indx<sz(ans) && ans[indx]=='0')indx++;
        if(indx==sz(ans))ans="0";
        else ans=ans.substr(indx);

        cout<<ans<<endl;
    }
return 0;
}