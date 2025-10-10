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
        vector<int> arr(n);
        set<int>zero,one,two;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0)zero.insert(i+1);
            if(arr[i]==1)one.insert(i+1);
            if(arr[i]==2)two.insert(i+1);
        }
        vector<pair<int,int>> op;
        for(int i=n-1;i>=0;i--){
            int cur=arr[i];
            if(two.count(i+1)){
                two.erase(i+1);
            }
            else if(one.count(i+1)){
                if(!two.empty()){
                    op.push_back({*two.begin(),i+1});
                    one.insert(*two.begin());
                    two.erase(two.begin());
                    one.erase(i+1);
                }else{
                    one.erase(i+1);
                }
            }
            else if(zero.count(i+1)){
                if(!two.empty()){
                    if(!one.empty()){
                        op.push_back({*one.begin(),i+1});
                        zero.insert(*one.begin());
                        one.erase(one.begin());
                        zero.erase(i+1);

                        op.push_back({*two.begin(),i+1});
                        one.insert(*two.begin());
                        two.erase(two.begin());
                    }
                }else if(!one.empty()){
                    op.push_back({*one.begin(),i+1});
                    zero.insert(*one.begin());
                    one.erase(one.begin());
                    zero.erase(i+1);
                }else{
                    zero.erase(i+1);
                }
            }
        }
        cout<<sz(op)<<endl;
        for(int i=0;i<sz(op);i++)cout<<op[i].first<<sp<<op[i].second<<endl;
    }
return 0;
}