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
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        int mex=0;
        for(int i=0;i<=n;i++){
            if(freq[i]==0){
                mex=i;
                break;
            }
        }

        bool smol_frq1=1;
        int big_frq_sum=0;
        for(int i=0;i<=n;i++){
            if(i<mex && freq[i]>1){
                smol_frq1=0;
                break;
            }
            if(i>mex)big_frq_sum+=freq[i];
        }

        //cout<<freq<<endl;
        //cout<<mex<<sp<<smol_frq1<<sp<<big_frq_sum<<endl<<endl;

        int ans=0;
        if(smol_frq1){
            for(int i=0;i<=n;i++){
                if(i<mex && freq[i]==1)ans+=i;
                else if(i>mex && freq[i]>=1){
                    if(big_frq_sum==1){
                        ans+=mex;
                    }else{
                        if(k&1)ans+=mex*freq[i];
                        else ans+=(mex+1)*freq[i];
                    }
                }
            }
        }else{
            int first=-1;
            for(int i=0;i<=n;i++){
                if(i<mex && freq[i]==1){
                    if(first==-1)ans+=i;
                    else{
                        if(k==1)ans+=i;
                        else if(k&1)ans+=first+1;
                        else ans+=first;
                    }
                }else if(i<mex && freq[i]>1){
                    if(first==-1)first=i;
                    if(k==1)ans+=mex;
                    else if(k&1)ans+=first+1;
                    else ans+=first;
                }else if(i>mex){
                    if(k==1)ans+=mex;
                    else if(k&1)ans+=first+1;
                    else ans+=first;
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}