#include<bits/stdc++.h>
using namespace std;
vector<int>v{11 ,12 ,3 ,2, 9 ,12};


void decimalToBinary(int decimal);

int modInverse(int A, int M) {
  
      if(__gcd(A, M) > 1){
          
          // modulo inverse does not exist
          return -1;
    }
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}

long long Mod=998244353;

void solve(){
//     for(int i=0;i<v.size();i++){
//         long long sum =0;
//         long long mul =1;
//         for(int k=0;k<=i;k++){
//             sum+=v[k];
//             mul*=v[k];
//         }
//         cout<<(sum&mul)<<endl;
//         decimalToBinary(sum);
//         cout<<endl;
//         decimalToBinary(mul);
//         cout<<endl;
//         cout<<v[i]<<endl;
//         decimalToBinary(v[i]);
//         cout<<endl;
//         cout<<endl;
//     }

// // for(int i=0 ;i<100;i++){
// //     decimalToBinary(i);
// //     cout<<" "<<i;
// //     cout<<endl;
// // }

    long long n;
    cin>>n;
    long long ans=1;
    vector<int>v1(n),v2(n);
    
    for(int i=0;i<n;i++){
        cin>>v1[i];
        // if(x!=y)ans*=2;
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
        // if(x!=y)ans*=2;
    }
for (int i = 1; i <= n; i++){
        cout << rand()%10000000;
        if(i!=n)cout<<" ";
        else cout<<endl;}



}



// void decimalToBinary(int decimal) { 

//     if (decimal == 0) { 

//         return; 

//     } else { 

//         decimalToBinary(decimal / 2); 

//         cout << decimal % 2; 

//     } 

// }
int main(){
    int t; cin >> t;
    while(t--) 
    solve();

    return 0;
}