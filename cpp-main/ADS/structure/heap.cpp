#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
private:
    vector<long long> arr;
    int size;
    int capacity;
    long long sum;

public:
    MaxHeap(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->arr.resize(capacity);
        this->sum = 0;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void insert(long long value) {
        if (size == capacity) {
            capacity *= 2;
            arr.resize(capacity);
        }
        size++;
        int i = size - 1;
        arr[i] = value;

        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    long long extractMax() {
        if (size == 0) return -1;
        if (size == 1) {
            size--;
            return arr[0];
        }

        long long root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }

    void check(int x) {
        if (size == capacity) {
            long long max = extractMax();
            if (max <= x) {
                insert(max);
                return;
            } else {
                insert(x);
                sum -= max;
                sum += x;
            }
        } else {
            insert(x);
            sum += x;
        }
    }

    long long getSum() {
        return sum;
    }
};


class MinHeap{
    private:
    vector<long long> arr;
    int size;
    int capacity;
    long long sum;

    public:

    MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->arr.resize(capacity);
        this->sum = 0;
    }

    void heapify(int i){
        int minimal = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] < arr[minimal]){
            minimal = left;
        }

        if(right < size && arr[right] < arr[minimal]){
            minimal = right;
        }

        if(minimal != i){
            swap(arr[i], arr[minimal]);
            heapify(minimal);
        }
    }


    void insert(long long value){
        if(size == capacity) {
            capacity *= 2;
            arr.resize(capacity);
        }
        size++;
        int i = size - 1;
        arr[i] = value;

        while(i != 0 && arr[(i-1)/2] > arr[i]){
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    long long extractMin(){
        if(size == 0) return -1;
        if(size == 1){
            size--;
            return arr[0];
        }

        long long root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }


    void check(int x){
        if(size == capacity){
            long long min = extractMin();
            if(min >= x){
                insert(min);
                return;
            }else{
                insert(x);
                sum-=min;
                sum+=x;
            }
        }else{
            insert(x);
            sum+=x;
        }
    }

    long long getSum(){
        return sum;
    }
};


int main(){

}