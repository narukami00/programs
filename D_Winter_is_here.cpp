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

int const N=1e6+20,mod=1e9+7;
int n,cnt[N],res[N],pw[N],ans;


void pre(){
    pw[0]=1;
    for(int i=1;i<N;i++){
        pw[i]=pw[i-1]*2 %mod;
    }
}
int32_t main(){
    Flashyy
    //tc
    {
        pre();
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int y=1;y*y<=x;y++){
                if(x%y==0){
                    cnt[y]++;
                    if(y*y!=x){
                        cnt[x/y]++;
                    }
                }
            }
        }

        for(int i=0;i<N;i++){
            if(cnt[i]){
                res[i]=cnt[i]*pw[cnt[i]-1] %mod;
            }
        }

        for(int i=N-1;i>1;i--){
            for(int j=2*i;j<N;j+=i){
                res[i]=(res[i]-res[j]+mod)%mod;
            }
            ans=(ans+i*res[i])%mod;
        }
        cout<<ans<<endl;
    }
return 0;
}