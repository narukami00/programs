#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int p = 0; p < k; p++) arr[l + p] = temp[p];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n;
    cin>>n;
    srand(time(0)); 
    vector<int> rand_vec;
    for (int i = 0; i < 100000; ++i) {
        int rand_num = rand() % 9000 + 1000; 
        rand_vec.push_back(rand_num);
    }
    mergeSort(rand_vec,0,99999);
    //for(int i=0;i<rand_vec.size();i++)cout<<rand_vec[i]<<" ";
    cout<<endl;
}

//time - 82ms