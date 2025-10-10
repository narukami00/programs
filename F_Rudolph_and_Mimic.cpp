#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
        vector<int>arr(n);
        cin>>arr;
        vector<int>cnt(10,0);
        for(int i=0;i<n;i++)cnt[arr[i]]++;
        int f=0;
        while(1){
            cout<<"- 0"<<endl;
            vector<int>temp(10,0);
            for(int i=0;i<n;i++){cin>>arr[i];temp[arr[i]]++;}
            for(int i=1;i<=9;i++){
                if(temp[i]==cnt[i]+1){
                    f=i;
                    break;
                }
            }
            if(f)break;
        }

        int rem=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=f){
                rem++;
            }
        }

        cout<<"- "<<rem;
        for(int i=0;i<n;i++)if(arr[i]!=f)cout<<sp<<i+1;
        cout<<endl;
        n-=rem;
        bool brk=0;
        while(1){
            for(int i=0;i<n;i++)cin>>arr[i];
            for(int i=0;i<n;i++){
                if(arr[i]!=f){
                    cout<<"! "<<i+1<<endl;
                    brk=1;break;
                }
            }
            if(brk)break;
            cout<<"- 0"<<endl;
        }
    }
return 0;
}