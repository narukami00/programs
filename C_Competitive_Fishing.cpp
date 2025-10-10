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
        int n,k; cin>>n>>k;
        string s; cin>>s;
        vector<int>sums;
        int sum=0,ans=1,t=0,f=0,c=0;

        for(int i=n-1;i>0;i--){
            if(s[i]=='1')sum+=1;
            else sum+=-1;
            if(sum>0){sums.push_back(sum);}
        }
        sort(all(sums));
        //reverse(all(sums));

        while(k>0 && !sums.empty()){
            k-=sums.back();
            sums.pop_back();
            ans++;
        }
        if(k>0)cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
return 0;
}