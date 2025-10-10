#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& heap, int indx){
    int largest=indx;
    int left=2*indx+1;
    int right=2*indx+2;

    if(left<heap.size() && heap[left]<heap[largest]){
        largest=left;
    }
    if(right<heap.size() && heap[right]<heap[largest]){
        largest=right;
    }

    if(largest!=indx){
        swap(heap[indx],heap[largest]);
        heapify(heap,largest);
    }
}

void heapifyWithSize(vector<int>& heap, int n,int indx){
    int largest=indx;
    int left=2*indx+1;
    int right=2*indx+2;

    if(left<n && heap[left]<heap[largest]){
        largest=left;
    }
    if(right<n && heap[right]<heap[largest]){
        largest=right;
    }

    if(largest!=indx){
        swap(heap[indx],heap[largest]);
        heapifyWithSize(heap,n,largest);
    }
}

void heapInsert(vector<int>& heap, int val){
    heap.push_back(val);
    int indx=heap.size()-1;

    while(indx!=0 && heap[(indx-1)/2]>heap[indx]){
        swap(heap[(indx-1)/2],heap[indx]);
        indx=(indx-1)/2;
    }
}

void heapDelete(vector<int>& heap, int val){
    int indx=-1;
    for(int i=0;i<heap.size();i++){
        if(heap[i]==val){
            indx=i;
            break;
        }
    }
    if(indx==-1)return;
    heap[indx]=heap.back();
    heap.pop_back();
    heapify(heap,indx);
}

void heapsort(vector<int>& heap){
    for(int i=heap.size()/2-1;i>=0;i--){
        heapify(heap,i);
    }
    for(int i=heap.size()-1;i>=0;i--){
        swap(heap[0],heap[i]);
        heapifyWithSize(heap,i,0);
    }
}

void printTree(const vector<int>& heap, int index = 0, int indent = 0) {
    if (index < heap.size()) {
        if (2 * index + 2 < heap.size()) {
            printTree(heap, 2 * index + 2, indent + 4);
        }

        if (indent) {
            cout << setw(indent) << ' ';
        }
        cout << heap[index] << endl;

        if (2 * index + 1 < heap.size()) {
            printTree(heap, 2 * index + 1, indent + 4);
        }
    }
}
int main(){
    vector<int> heap={10,20,11,24,33,54,45,12,9,8,7,55,21,99,3};

    for(int i=heap.size()/2-1;i>=0;i--){
        heapify(heap,i);
    }

    for(int i=0;i<heap.size();i++)cout<<heap[i]<<" ";
    cout<<endl<<endl;

    printTree(heap,0,0);
    cout<<endl<<endl;

    heapsort(heap);

    for(int i=0;i<heap.size();i++)cout<<heap[i]<<" ";
    cout<<endl<<endl;

    printTree(heap,0,0);
    cout<<endl<<endl;
}
