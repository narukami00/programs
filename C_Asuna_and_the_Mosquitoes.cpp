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
        int n;
        cin>>n;
        vector<int> odd,even;
        int sum=0;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x%2==0) {
                even.push_back(x);
            }
            else {
                odd.push_back(x);
            }
            sum+=x;
        }
        int ans=0;

        if(odd.empty()){
            ans=*max_element(all(even));
        }else if(even.empty()){
            ans=*max_element(all(odd));
        }else{
            ans=sum-odd.size()+1;
        }
        
        cout<<ans<<endl;
    }
return 0;
}