#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define FastAF ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()
#include<cmath>

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    FastAF
    tc
    {
        int n,k,i=1,ans,flag=1;
        cin>>n>>k;
        i=(k+n-2)/(n-1);
        k-=(n-1)*i;
        ans=n*i+k-1;
        /*
        while(flag){
            k-=(n-1);
            if(k<=0){
                ans=n*i+k-1;
                flag=0;
            }
            i++;
        }*/
        cout<<ans<<endl;
    }
return 0;
}