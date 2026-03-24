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
        int n,k,l,r;
        cin>>n>>k>>l>>r;
        l=max(l,k);
        vector<int>a(n);
        cin>>a;
        map<int,int>freq1,freq2;
        int i=0,j=0,kk=0,ans=0;
        while(kk<n){
            freq1[a[kk]]++;
            freq2[a[kk]]++;
            while(sz(freq1)>k){
                freq1[a[i]]--;
                if(freq1[a[i]]==0)freq1.erase(a[i]);
                i++;
            }
            while(sz(freq2)>k-1){
                freq2[a[j]]--;
                if(freq2[a[j]]==0)freq2.erase(a[j]);
                j++;
            }
            int lb=max(i,kk-r+1),ub=min(j-1,kk-l+1);
            if(lb<=ub)ans+=ub-lb+1;
            kk++;
        }
        cout<<ans<<endl;
    }
return 0;
}