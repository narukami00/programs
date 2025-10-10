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
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int32_t main(){
    Flashyy
    tc {
        int n;
        cin >> n;
        vector<int> b(2*n);
        cin >> b;
        sort(all(b));

        int sum=0;
        for(int i=0;i<2*n;i++){
            if(i<n-1)sum-=b[i];
            else sum+=b[i];
        }
        
        vector<int> ans(2*n+1,0);
        ans[1]=sum;
        ans[0]=b[2*n-1];
        int odd=2,eve=3;
        for(int i=0;i<(2*n)-1;i++){
            if(i<n-1){
                ans[eve]=b[i];
                eve+=2;
            }else{
                ans[odd]=b[i];
                odd+=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
