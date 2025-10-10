#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void heapSort(vector<int>& arr, int left, int right) {
    make_heap(arr.begin() + left, arr.begin() + right + 1);
    sort_heap(arr.begin() + left, arr.begin() + right + 1);
}

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left + (right - left) / 2];
    int i = left, j = right;
    while (true) {
        while (arr[i] < pivot) ++i;
        while (arr[j] > pivot) --j;
        if (i >= j) return j;
        swap(arr[i], arr[j]);
        ++i;
        --j;
    }
}

void quickSort(vector<int>& arr, int left, int right, int depth_limit) {
    if (right - left + 1 <= 16) {
        insertionSort(arr, left, right);
        return;
    }

    if (depth_limit == 0) {
        heapSort(arr, left, right);
        return;
    }

    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot, depth_limit - 1);
    quickSort(arr, pivot + 1, right, depth_limit - 1);
}

void introSort(vector<int>& arr) {
    int depth_limit = 2 * log(arr.size());
    quickSort(arr, 0, arr.size() - 1, depth_limit);
}

int main() {
    int n;
    cin >> n;
    srand(time(0));
    vector<int> rand_vec;
    for (int i = 0; i < 100000; ++i) {
        int rand_num = rand() % 9000 + 1000;
        rand_vec.push_back(rand_num);
    }

    introSort(rand_vec);

    //for (int x : rand_vec) cout << x << " ";
    cout << endl;
}


//time - 53ms


/*
#include<bits/stdc++.h>
using namespace std;

template <typename rand_acc_it>
void insertionSort(rand_acc_it begin, rand_acc_it end) {
    for (rand_acc_it i = begin; i != end; ++i) {
        for (rand_acc_it j = i; j != begin && *j < *(j - 1); --j) {
            std::iter_swap(j, j - 1);
        }
    }
}

template <typename rand_acc_it>
void heapSort(rand_acc_it begin, rand_acc_it end) {
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}

template <typename rand_acc_it>
void quickSort(rand_acc_it begin, rand_acc_it end, int depth_limit) {
    if (end - begin <= 16) {
        insertionSort(begin, end);
        return;
    }

    if (depth_limit == 0) {
        heapSort(begin, end);
        return;
    }

    rand_acc_it pivot = std::partition(begin, end, [mid = *(begin + (end - begin) / 2)](const auto& elem) {
        return elem < mid;
    });

    quickSort(begin, pivot, depth_limit - 1);
    quickSort(pivot, end, depth_limit - 1);
}

template <typename rand_acc_it>
void introSort(rand_acc_it begin, rand_acc_it end) {
    int depth_limit = 2 * log(end - begin);
    quickSort(begin, end, depth_limit);
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
    introSort(rand_vec.begin(),rand_vec.end());
    //for(int i=0;i<rand_vec.size();i++)cout<<rand_vec[i]<<" ";
    cout<<endl;
}

*/