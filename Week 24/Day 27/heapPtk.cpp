#include <iostream>
#include <iomanip>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int heap[], int &size, int data, int cap) {
    heap[size] = data;
    int i = size;
    size++;
    
    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void minHeapify(int heap[], int size, int i){
    int small = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < size && heap[left] < heap[small]) small = left;
    if(right < size && heap[right] < heap[small]) small = right;
    
    if(small != i) {
        swap(&heap[i], &heap[small]);
        minHeapify(heap, size, small);
    }
}

void removeRoot(int heap[], int &size) {
    if(size == 0) return;
    
    heap[0] = heap[size - 1];
    size--;
    
    minHeapify(heap, size, 0);
}

void display(int heap[], int size) {
    for(int i = 0; i < size; ++i) {
        cout << heap[i] <<" ";
    }
    cout << endl;
    return;
}

void max(int heap[], int size){
    int max = 0, sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += heap[i];
        if(heap[i] > max) {
            max = heap[i];
        }
    }
    cout << "Maximum Value: " << max <<endl;
    cout << "Sum of nodes: " << sum << endl;
    cout << "Average of nodes: " <<fixed << setprecision(2) << (float)sum/size <<endl;
}

int main() {
    int n;
    cin>>n;
    
    int cap = n;
    int size = 0;
    int heap[cap];
    
    for(int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insert(heap, size, data, cap);
    }
    
    cout << "Min Heap: ";
    display(heap, size);
    cout << "Root node: "<<heap[0] <<endl;
    removeRoot(heap, size);
    
    max(heap,size);
    return 0;
}