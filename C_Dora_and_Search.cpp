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

int32_t main(){
    Flashyy
    tc
    {
        int n,f=0;
        cin>>n;
        vector<int> arr(n);
        cin>>arr;
        int l=0,r=n-1,min=1,max=n;
        while(l<=r){
            if(arr[l]==min){
                l++;
                min++;
            }
            else if(arr[l]==max){
                l++;
                max--;
            }
            else if(arr[r]==min){
                r--;
                min++;
            }
            else if(arr[r]==max){
                r--;
                max--;
            }
            else break;
        }
        
        if(l<=r) cout<<l+1<<" "<<r+1<<endl;
        else cout<<"-1"<<endl;
    }
return 0;
}