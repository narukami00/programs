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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),d(m),f(k);
        cin>>a;cin>>d;cin>>f;
        
        vector<int>gap(n-1);
        for(int i=1;i<n;i++)gap[i-1]=a[i]-a[i-1];
        sort(rall(gap));
        int mx1=gap[0];
        int mx2=(n-1>=2?gap[1]:0ll);

        int mn=0,mx=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]==mx1){
                mn=a[i-1];
                mx=a[i];
                break;
            }
        }

        sort(all(f));
        int ans=mx1;
        int mid=(mn+mx)/2;
        
        for(auto it:d){
            int l=mn-it+1;
            int r=mx-it-1;
            int target=mid-it;
            auto x=lower_bound(all(f),target);

            for(int s=0;s<2;s++){
                if(x==f.end() && s==0)x=prev(f.end());
                else if(x==f.begin() && s==1)break;
                else if(s==1)x--;
                int choose=*x;
                if(choose<l || choose>r)continue;
                int left=it+choose-mn;
                int right=mx-it-choose;
                int nmx=max(mx2,max(left,right));
                ans=min(ans,nmx);
            }
        }
        cout<<ans<<endl;
    }
return 0;
}