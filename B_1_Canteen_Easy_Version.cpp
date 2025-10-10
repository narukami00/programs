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
        vector<int>a(2*n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            a[i]=a[i]-x;
            a[i+n]=a[i];
        }
        for(int i=1;i<=2*n;i++)a[i]+=a[i-1];
        stack<int>st;
        int ans=0;
        for(int i=2*n;i>=1;i--){
            while(!st.empty() && a[st.top()]>a[i]){
                st.pop();
            }
            if(i<=n)ans=max(ans,st.top()-i);
            st.push(i);
        }
        cout<<ans<<endl;
    }
return 0;
}