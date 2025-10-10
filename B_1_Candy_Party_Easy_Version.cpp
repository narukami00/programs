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
        int n,sum=0;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        
        if(sum%n!=0){
            no;continue;
        }

        int avg=sum/n;
        vector<int>out(31,0),in(31,0);
        bool f=1;

        for(int cur:arr){
            int dif=cur-avg;
            if(dif==0)continue;
            bool found=0;
            for(int i=0;i<=30;i++){
                int give=1ll<<i;
                int take=give-dif;
                if(take>0 && !(take&(take-1))){
                    int j=__builtin_ctzll(take);
                    out[i]++;
                    in[j]++;
                    found=1;
                    break;
                }
            }
            if(!found){
                f=0;
                break;
            }
        }

        if(!f){
            no;continue;
        }

        for(int i=0;i<=30;i++){
            if(out[i]!=in[i]){
                f=0;
                break;
            }
        }

        if(f)yes;
        else no;

    }
return 0;
}