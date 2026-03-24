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
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m),c(m);
        cin>>a>>b>>c;

        multiset<int>s;
        for(int i=0;i<n;i++)s.insert(a[i]);

        vector<pair<int,int>>st1;
        vector<int>st2;

        for(int i=0;i<m;i++){
            if(c[i]>0)st1.pb({b[i],c[i]});
            else st2.pb(b[i]);
        }

        sort(all(st1));
        sort(all(st2));

        int ans=0;
        vector<int>left;

        for(auto [l,g]:st1){
            while(!s.empty() && *s.begin()<l){
                left.pb(*s.begin());
                s.erase(s.begin());
            }

            if(s.empty())break;

            int sw=*s.begin();
            s.erase(s.begin());
            s.insert(max(sw,g));
            ans++;
        }   

        for(auto it:s)left.pb(it);

        sort(all(left));

        int i=0,j=0;
        while(i<st2.size() && j<left.size()){
            if(left[j]>=st2[i]){
                ans++;
                i++;
                j++;
            }else j++;
        }
        cout<<ans<<endl;
    }
return 0;
}