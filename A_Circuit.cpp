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
        vector<int> arr(2*n);
        int zeros=0,ones=0;
        for(int i=0;i<2*n;i++){
            int x;
            cin>>x;
            arr[i]=x;
            if(x==0)zeros++;
            else ones++;
        }

        sort(all(arr));
        int mini=0,maxx=0;
        for(int i=0;i<2*n-1;i+=2){
            if(arr[i]!=arr[i+1]){
                mini++;
            }
        }
        maxx=min(zeros,ones);

        cout<<mini<<sp<<maxx<<endl;

    }
return 0;
}