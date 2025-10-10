#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    ll s=0,ans=LLONG_MAX;
    cin>>n;
    vector<ll> diff(n);
    for(ll i=0;i<n;i++){cin>>diff[i];s+=diff[i];}
    vector<bool> dp(s/2+1,false);
    dp[0]=true;
    for(ll i=0;i<n;i++){
        for(ll j=s/2;j>=diff[i];j--){
            dp[j]=dp[j]||dp[j-diff[i]];
        }
    }for(ll j=s/2;j>=0;j--){
        if(dp[j]==true){ans=abs(s-2*j);break;}
    }
    cout<<ans<<endl;

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void generateSubsetSums(const vector<ll>& arr, vector<ll>& subsetSums) {
    int n = arr.size();
    int numSubsets = 1 << n; // 2^n possible subsets
    for (int mask = 0; mask < numSubsets; ++mask) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        subsetSums.push_back(sum);
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> diff(n);
    for (int i = 0; i < n; i++) {
        cin >> diff[i];
    }

    // Split the array into two halves
    vector<ll> firstHalf(diff.begin(), diff.begin() + n / 2);
    vector<ll> secondHalf(diff.begin() + n / 2, diff.end());

    // Generate all subset sums for each half
    vector<ll> firstHalfSums, secondHalfSums;
    generateSubsetSums(firstHalf, firstHalfSums);
    generateSubsetSums(secondHalf, secondHalfSums);

    // Sort the subset sums of the second half
    sort(secondHalfSums.begin(), secondHalfSums.end());

    ll totalSum = accumulate(diff.begin(), diff.end(), 0LL);
    ll minDifference = LLONG_MAX;

    // Find the closest sum by comparing sums from first half and second half
    for (ll sum1 : firstHalfSums) {
        ll target = totalSum / 2 - sum1;
        auto it = lower_bound(secondHalfSums.begin(), secondHalfSums.end(), target);
        
        if (it != secondHalfSums.end()) {
            minDifference = min(minDifference, abs(totalSum - 2 * (sum1 + *it)));
        }
        if (it != secondHalfSums.begin()) {
            --it;
            minDifference = min(minDifference, abs(totalSum - 2 * (sum1 + *it)));
        }
    }

    cout << minDifference << endl;
    return 0;
}
*/