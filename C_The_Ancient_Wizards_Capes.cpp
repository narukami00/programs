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
        cin>>a;

        if(n==1){
            cout<<2<<endl;
            continue;
        }

        vector<int>diff(n);
        for(int i=1;i<n;i++){
            diff[i]=a[i]-a[i-1]+1;
        }

        int ans=0;
        vector<int>x(n);
        for(int k=0;k<=1;k++){
            x[0]=k;bool f=1;
            for(int i=1;i<n;i++){
                x[i]=diff[i]-x[i-1];
                if(x[i]!=0 && x[i]!=1){
                    f=0;break;
                }
            }
            
            if(f){
                int sum=1;
                for(int i=1;i<n;i++){
                    if(x[i]==0)sum++;
                }
                if(sum==a[0])ans++;
            }
        }

        cout<<ans<<endl;
    }
return 0;
}