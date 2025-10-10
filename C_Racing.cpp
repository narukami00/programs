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
        vector<int>d(n),l(n),r(n);
        cin>>d;
        for(int i=0;i<n;i++)cin>>l[i]>>r[i];

        int lo=0,hi=0;
        vector<pair<int,int>>rng(n+1);rng[0]={0,0};
        bool f=1;

        for(int i=0;i<n;i++){
            int nlo,nhi;
            if(d[i]==0){
                nlo=lo;
                nhi=hi;
            }else if(d[i]==1){
                nlo=lo+1;
                nhi=hi+1;
            }else{
                nlo=lo;
                nhi=hi+1;
            }

            nlo=max(nlo,l[i]);nhi=min(nhi,r[i]);
            if(nlo>nhi){
                f=0;
                break;
            }
            lo=nlo;
            hi=nhi;
            rng[i+1]={lo,hi};
        }

        if(!f){
            cout<<-1<<endl;
            continue;
        }

        vector<int>h(n+1);
        h[n]=lo;
        for(int i=n-1;i>=0;i--){
            int prev=h[i+1];
            if(d[i]==0 || d[i]==1){
                h[i]=h[i+1]-d[i];
            }else{
                if(rng[i].f<=prev && rng[i].s>=prev){
                    h[i]=prev;
                    d[i]=0;
                }else{
                    h[i]=prev-1;
                    d[i]=1;
                }
            }
        }
        
        cout<<d<<endl;
    }
return 0;
}