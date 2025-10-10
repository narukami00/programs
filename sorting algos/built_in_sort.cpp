#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    srand(time(0)); 
    vector<int> rand_vec;
    for (int i = 0; i < 100000; ++i) {
        int rand_num = rand() % 9000 + 1000; 
        rand_vec.push_back(rand_num);
    }
    sort(rand_vec.begin(),rand_vec.end());
    //for(int i=0;i<rand_vec.size();i++)cout<<rand_vec[i]<<" ";
    cout<<endl;
}

//time - 59ms