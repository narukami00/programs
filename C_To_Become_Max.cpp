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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int lb=0,ub=*max_element(all(arr))+k,ans=0;

        while(lb<=ub){
            int target=(lb+ub)/2;
            bool valid=false;

            for(int i=0;i<n;i++){
                vector<int> needed(n);
                needed[i]=target;

                int used=0;
                for(int j=i;j<n;j++){
                    if(needed[j]<=arr[j]) break;

                    if(j+1>=n){
                        used=k+1;
                        break;
                    }

                    used+=needed[j]-arr[j];
                    needed[j+1]=max(0ll,needed[j]-1);
                }

                if(used<=k) valid=true;
            }
            if(valid){
                ans=target;
                lb=target+1;
            }else ub=target-1;
        }

        cout<<ans<<endl;
        
    }
return 0;
}