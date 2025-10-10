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

int pre[322][200322],prei[322][200322];

int32_t main(){
    Flashyy
    tc
    {
        int n,q;
        cin>>n>>q;
        vector<int>a(n);
        int p=1;
        while(p*p<n)p++;
        cin>>a;

        for(int i=0;i<p;i++){
            for(int j=0;j<=i;j++){
                pre[i][j]=0;
                prei[i][j]=0;
            }

            for(int j=0;j<n;j++){
                pre[i][j+i+1]=pre[i][j]+a[j];
                prei[i][j+i+1]=prei[i][j]+a[j]*(j/(i+1) +1);
            }
        }

        while(q--){
            int s,d,k,ans=0;
            cin>>s>>d>>k;
            s--;
            if(d>p){
                for(int i=s;i<=s+(k-1)*d;i+=d){
                    ans+=a[i]*((i-s)/d +1);
                }
                cout<<ans<<sp;
                continue;
            }

            int first=s,last=s+d*k-d;
            cout<<prei[d-1][last+d]-prei[d-1][first]-(pre[d-1][last+d]-pre[d-1][first])*(first/d)<<sp;
        }

        cout<<endl;
    }
return 0;
}