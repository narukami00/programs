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

long long mergeCount(vector<int>& arr, int left, int right) {
    if(right - left <= 1) return 0;
    int mid = (left + right) / 2;
    long long inv_count = mergeCount(arr, left, mid) + mergeCount(arr, mid, right);
    vector<int> tmp;
    int i = left, j = mid;
    while(i < mid && j < right){
        if(arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else {
            tmp.push_back(arr[j++]);
            inv_count += mid - i; 
        }
    }
    while(i < mid)
        tmp.push_back(arr[i++]);
    while(j < right)
        tmp.push_back(arr[j++]);
    for (int k = left; k < right; k++){
        arr[k] = tmp[k - left];
    }
    return inv_count;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        cin>>a;
        cin>>b;

        vector<int>sa=a,sb=b;
        sort(all(sa));
        sort(all(sb));

        if(sa!=sb){no;continue;}

        vector<int>ca=a,cb=b;
        int ia=mergeCount(ca,0,n);
        int ib=mergeCount(cb,0,n);

        if((ia%2)==(ib%2))yes;
        else no;
    }
return 0;
}