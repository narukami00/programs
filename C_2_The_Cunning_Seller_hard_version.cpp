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
    vector<int>powa(22);
    powa[0]=1;
    for(int i=1;i<22;i++)powa[i]=powa[i-1]*3;
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<int>deal(22,0);
        deal[0]=n;
        int cnt=n;
        for(int i=0;i<=20;i++){
            if(cnt<=k)break;
            if(deal[i]<3)continue;
            int merge=(cnt-k+1)/2;
            int pos=deal[i]/3;
            if(pos<merge)merge=pos;
            deal[i]-=merge*3;
            deal[i+1]+=merge;
            cnt-=merge*2;
        }

        if(cnt>k){
            cout<<-1<<endl;
            continue;
        }

        int ans=3*n;
        for(int i=1;i<=20;i++){
            if(deal[i]>0){
                ans+=deal[i]*i*powa[i-1];
            }
        }
        cout<<ans<<endl;
    }
return 0;
}