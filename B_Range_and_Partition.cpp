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
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        cin>>a;

        vector<int>temp=a;
        sort(all(temp));
        int need=(n+k+1)/2;
        pair<int,pair<int,int>>ans={n+1,{-1,-1}};
        for(int i=0;i<n-need+1;i++){
            ans=min(ans,{temp[i+need-1]-temp[i],{temp[i],temp[i+need-1]}});
        }
        cout<<ans.s.f<<sp<<ans.s.s<<endl;
        
        int found=0,cur=0,last=1;
        for(int i=0;i<n;i++){
            if(a[i]>=ans.s.f && a[i]<=ans.s.s)cur++;
            else cur--;

            if(cur>0 && found<k-1){
                cout<<last<<sp<<i+1<<endl;
                last=i+2;
                found++;
                cur=0;
            }
        }
        cout<<last<<sp<<n<<endl;
    }
return 0;
}