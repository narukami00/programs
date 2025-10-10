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
    //tc
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr;

        vector<int>pos(n+1);
        for(int i=0;i<n;i++){
            pos[arr[i]]=i;
        }

        vector<int>curr(n);
        for(int i=0;i<n;i++){
            curr[i]=i+1;
        }

        vector<pair<int,int>> ans;

        for(int i=n-1;i>=0;i--){
            int cur=arr[i];
            int p=0;
            for(int j=0;j<n;j++){
                if(curr[j]==cur){
                    p=j;
                    break;
                }
            }

            while(p>0){
                ans.pb({cur,curr[p-1]});
                swap(curr[p],curr[p-1]);
                p--;
            }

            while(p<n-1){
                int b=curr[p+1];
                if(pos[b]<pos[cur]){
                    ans.pb({b,cur});
                    swap(curr[p],curr[p+1]);
                    p++;
                }else break;
            }
        }

        cout<<sz(ans)<<endl;
        for(auto &it:ans)cout<<it.first<<sp<<it.second<<endl;

    }
return 0;
}