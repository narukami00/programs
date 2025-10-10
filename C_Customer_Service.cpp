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



int32_t main(){
    Flashyy
    tc
    {
        int n;cin>>n;
        vector<vector<int>> arr(n+1,vector<int>(n+1));
        vector<int> suff(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>arr[i][j];
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                if(arr[i][j]!=1) break;
                suff[i]++;
            }
        }

        multiset<int>s;
        for(int i=1;i<=n;i++) s.insert(suff[i]);

        int ans=1;

        while(!s.empty()){
            int curr=*s.begin();
            if(curr>=ans) ans++;
            s.erase(s.find(curr));
        }

        cout<<min(ans,n)<<endl;
        
    }
return 0;
}