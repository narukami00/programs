#include<bits/stdc++.h>
using namespace std;

const int MIN_MERGE = 32;

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void merge(vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    vector<int> left(len1), right(len2);

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void timSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i += MIN_MERGE)
        insertionSort(arr, i, min(i + MIN_MERGE - 1, n - 1));

    for (int size = MIN_MERGE; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
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
    timSort(rand_vec);
    //for(int i=0;i<rand_vec.size();i++)cout<<rand_vec[i]<<" ";
    cout<<endl;
}

//time - 69ms (min merge 64)
//time - 68ms (min merge 32)

//generic implementation
/*
#include <bits/stdc++.h>
using namespace std;

const int MIN_MERGE = 32;

template <typename RandIt, typename Compare>
void insertionSort(RandIt begin, RandIt end, Compare comp) {
    for (RandIt i = begin + 1; i < end; ++i) {
        auto key = std::move(*i);
        RandIt j = i;
        while (j > begin && comp(key, *(j - 1))) {
            *j = std::move(*(j - 1));
            --j;
        }
        *j = std::move(key);
    }
}

template <typename RandIt, typename Compare>
void merge(RandIt left, RandIt mid, RandIt right, Compare comp) {
    using Value = typename iterator_traits<RandIt>::value_type;
    vector<Value> leftVec(left, mid);
    vector<Value> rightVec(mid, right);

    auto i = leftVec.begin(), j = rightVec.begin();
    RandIt k = left;

    while (i != leftVec.end() && j != rightVec.end()) {
        if (!comp(*j, *i)) {
            *k++ = std::move(*i++);
        } else {
            *k++ = std::move(*j++);
        }
    }

    while (i != leftVec.end()) *k++ = std::move(*i++);
    while (j != rightVec.end()) *k++ = std::move(*j++);
}

template <typename RandIt, typename Compare>
void timSort(RandIt begin, RandIt end, Compare comp) {
    int n = end - begin;

    // Sort small runs with insertion sort
    for (int i = 0; i < n; i += MIN_MERGE) {
        RandIt left = begin + i;
        RandIt right = begin + min(i + MIN_MERGE, n);
        insertionSort(left, right, comp);
    }

    // Merge runs using bottom-up merge sort
    for (int size = MIN_MERGE; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            RandIt start = begin + left;
            RandIt mid = begin + min(left + size, n);
            RandIt right = begin + min(left + 2 * size, n);
            if (mid < right) {
                merge(start, mid, right, comp);
            }
        }
    }
}

// Overload for default comparator
template <typename RandIt>
void timSort(RandIt begin, RandIt end) {
    timSort(begin, end, std::less<typename iterator_traits<RandIt>::value_type>());
}

*/