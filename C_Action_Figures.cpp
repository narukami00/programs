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
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
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
        string s;
        cin>>s;
        int ones=0,zeros=0;
        stack<int>used_z;
        queue<int>used_o;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=i+1;
                zeros++;
                used_z.push(i);
            }else {
                ones++;
                used_o.push(i);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ones--;
                if(!used_o.empty() && i==used_o.front()){
                    if(zeros>0){
                        zeros--;
                        used_z.pop();
                    }else ans+=used_o.front()+1;
                    used_o.pop();
                    continue;
                }

                if(zeros>0){
                    zeros--;
                    used_z.pop();
                }else if(!used_o.empty() && ones>0){
                    ones--;
                    ans+=used_o.front()+1;
                    used_o.pop();
                }
            }else if(s[i]=='0'){
                if(!used_z.empty() && used_z.top()==i){
                    used_z.pop();
                    zeros--;
                }
            }
        }

        cout<<ans<<endl;
    }
return 0;
}