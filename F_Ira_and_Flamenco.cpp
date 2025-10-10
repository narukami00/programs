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

const int mod=1e9+7;
int modexp(int base, int exp) {
    int res = 1;
    while(exp) {
        if(exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int inv(int x) {
    return modexp(x, mod - 2);
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        map<int,int>freq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            freq[x]++;
            arr[i]=x;
        }

        if(m==1){
            cout<<n<<endl;
            continue;
        }

        set<int>st;
        for(int i=0;i<n;i++)st.insert(arr[i]);

        queue<int>q;
        for(auto it:st)q.push(it);

        if(sz(q)<m){
            cout<<0<<endl;
            continue;
        }
        
        int ans=0,res=1;
        deque<int>dek;
        for(int i=0;i<m;i++){
            int x=q.front();q.pop();
            dek.pb(x);
            res=(res*freq[x])%mod;
        }
        
        if(dek.back()-dek.front()<m){
            ans=(ans+res)%mod;
        }
        
        while(!q.empty()){
            int del=dek.front();
            dek.pop_front();
            res=(res*inv(freq[del]))%mod;
            int x=q.front();
            q.pop();
            dek.pb(x);
            res=(res*freq[x])%mod;

            if(dek.back()-dek.front()<m){
                ans=(ans+res)%mod;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}