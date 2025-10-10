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

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
void solve(){
        int n;
        cin>>n;
        vector<int> arr(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i]=x;
            mp[x]++;
        }
        int mex=0;
        for(int i=0;i<1e5+7;i++){
            if(mp[i]==0){
                mex=i;
                break;
            }
        }
        mp.clear();
        if(mex==0){
            cout<<2<<endl;
            cout<<"1 1"<<endl;
            cout<<"2 "<<n<<endl;
            return;
        }
        vector<pair<int,int>> pr;
        int l=0;cout<<mex<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]<mex)mp[arr[i]]=1;
            if(mp.size()==mex){
                pr.push_back(make_pair(l+1,i+1));
                l=i+1;
                mp.clear();
            }
        }
        pr[pr.size()-1].second=n;
        if(pr.size()<2)cout<<"-1"<<endl;
        else{
            cout<<pr.size()<<endl;
            for(int i=0;i<pr.size();i++){
                cout<<pr[i].first<<" "<<pr[i].second<<endl;
            }
        }
    }

int32_t main(){
    Flashyy
    tc
    {
        solve();
    }
return 0;
}