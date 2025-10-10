#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        vector<int> par;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            cin>>arr[i].second;
            if(arr[i].first==arr[i].second){
                mp[arr[i].first]++;
                if(mp[arr[i].first]==1)par.push_back(arr[i].first);
                }
        }
        sort(all(par));
        for(int i=0;i<n;i++){
            if(arr[i].first==arr[i].second){
                if(mp[arr[i].first]==1)cout<<"1";
                else cout<<"0";
            }
            else{
                int x=arr[i].first;
                int y=arr[i].second;
                int l=y-x+1;
                int c=upper_bound(all(par),y)-lower_bound(all(par),x);
                if(c<l)cout<<"1";
                else cout <<"0";
            } 
        }

        cout<<endl;

    }
return 0;
}