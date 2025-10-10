#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi, high);
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
    quickSort(rand_vec,0,99999);
    //for(int i=0;i<rand_vec.size();i++)cout<<rand_vec[i]<<" ";
    cout<<endl;
}

//time - 63ms