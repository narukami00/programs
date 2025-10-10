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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        cin>>arr;
        if(k>=3){
            cout<<"0"<<endl;
        }
        else if(k==1){
            sort(all(arr));
            int mini=arr[0];
            for(int i=0;i<n-1;i++) mini=min(mini,arr[i+1]-arr[i]);
            cout<<mini<<endl;
        }
        else if(k==2){
            sort(all(arr));
            int mini=arr[0];
            for(int i=0;i<n-1;i++) mini=min(mini,arr[i+1]-arr[i]);
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                int diff=abs(arr[i]-arr[j]);
                int bs=lower_bound(all(arr),diff)-arr.begin();
                if(bs<n)mini=min(mini,arr[bs]-diff);
                if(bs>0)mini=min(mini,diff-arr[bs-1]);
                }
            }
            cout<<mini<<endl;  
        }
    }
return 0;
}