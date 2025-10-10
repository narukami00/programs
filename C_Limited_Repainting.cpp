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

bool possible(int x, string& s, vector<int>& arr, int k){
    int n=s.size();
    int op=0;
    int i=0;
    while(i<n){
        if(s[i]=='R' && arr[i]>x){
            i++;
            continue;
        }
        bool paint=false;
        int j=i;
        while(j<n && !(s[j]=='R' && arr[j]>x)){
            if(s[j]=='B' && arr[j]>x) paint=true;
            j++;
        }
        if(paint) op++;
        i=j;
    }
    return (op<=k);
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> arr(n);
        cin>>arr;

        int lb=0,ub=*max_element(all(arr));
        int ans=ub;

        while(lb<=ub){
            int mid=(ub+lb)/2;
            if(possible(mid,s,arr,k)){
                ans=mid;
                ub=mid-1;
            }else lb=mid+1;
        }

        cout<<ans<<endl;
    }
return 0;
}