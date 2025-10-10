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
        string s;
        cin>>s;
        int n=s.size();
        int i=0;
        while(i<n/2 && s[i]==s[n-i-1])i++;
        n-=2*i;
        s=s.substr(i,n);
        int ans=n;

        for(int z=0;z<2;z++){
            int l=0,r=n;
            while(l<=r){
                int m=(l+r)/2;
                vector<int> cnt(26);
                for(int i=0;i<m;i++){
                    cnt[s[i]-'a']++;
                }
                bool ok=1;
                for(int i=0;i<min(n/2,n-m);i++){
                    char c=s[n-i-1];
                    if(i<m){
                        ok&=cnt[c-'a']>0;
                        cnt[c-'a']--;
                    }else{
                        ok&=(c==s[i]);
                    }
                }
                for(auto it:cnt){
                    ok&=(it%2==0);
                }
                if(ok) r=m-1;
                else l=m+1;
            }
            ans=min(ans,r+1);
            reverse(all(s));
        }
        
        cout<<ans<<endl;
    }
return 0;
}