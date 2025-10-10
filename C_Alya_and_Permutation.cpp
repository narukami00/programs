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
        int n, f=0;
        cin>>n;
        int ans=0;
        vector<int> arr;
        if(n==5){
            ans=5;
            arr.push_back(2);
            arr.push_back(1);
            arr.push_back(3);
            arr.push_back(4);
            arr.push_back(5);
        }
        else if(n==6){
            ans=7;
            arr.push_back(1);
            arr.push_back(2);
            arr.push_back(4);
            arr.push_back(6);
            arr.push_back(5);
            arr.push_back(3);
        }
        else if(n==7){
            ans=7;
            arr.push_back(1);
            arr.push_back(2);
            arr.push_back(4);
            arr.push_back(6);
            arr.push_back(5);
            arr.push_back(3);
            arr.push_back(7);
        }else{
            if(n%2!=0){
            n--;
            f=1;
        }
        
        int x=log2(n);
        ans=pow(2,x+1)-1;
        int val1=pow(2,x)-2;
        int val2=pow(2,x)-1;
        int val3=pow(2,x);
 
        if(f){
            arr.push_back(n+1);
            //n++;
            ans=n+1;
        }
        arr.push_back(val3);
        arr.push_back(val2);
        arr.push_back(val1);
        arr.push_back(3);
        arr.push_back(1);

        for(int i=2;i<=n;i++){
            if(i!=val1 && i!=val2 && i!=val3 && i!=1 && i!=3){
                arr.push_back(i);
            }
        }
        reverse(all(arr));
        }
        

        cout<<ans<<endl;
        cout<<arr<<endl;

    }
return 0;
}