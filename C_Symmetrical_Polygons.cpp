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
        vector<int>a(n);
        map<int,int>freq;
        vector<int>odd,even;
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        for(auto it:freq){
            if(it.s==1)odd.pb(it.f);
            else{
                even.pb(it.f);
                if(it.s%2!=0)odd.pb(it.f);
            }
        }
        int ans=0,cnt=0;
        for(int i=0;i<sz(even);i++){
            cnt+=(freq[even[i]]/2)*2;
            ans+=even[i]*((freq[even[i]]/2)*2);
        }

        if(ans==0){
            cout<<0<<endl;
            continue;
        }

        int cand=0;
        for(int i=0;i<sz(odd);i++){
            if(ans>odd[i])cand=max(cand,odd[i]);
        }

        sort(all(odd));     
        int cand2=0;
        for(int i=1;i<sz(odd);i++){
            if(odd[i]-odd[i-1]<ans)cand2=max(cand2,odd[i]+odd[i-1]);
        }

        if(cnt==2 && max(cand,cand2)==0){
            cout<<0<<endl;
            continue;
        }

        cout<<ans+max(cand,cand2)<<endl;
    }
return 0;
}