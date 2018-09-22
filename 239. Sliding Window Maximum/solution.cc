#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

class HeapSorter {
private:
    struct Elem {
        int val;
        int seq;
        Elem(int value, int no): val(value), seq(no) {}
    };
public:
    HeapSorter(const vector<int> &nums, int cap):capacity(cap), maxSeq(0) {
        assert(nums.size() >= cap);

        maxHeap.reserve(cap);

        for (int i = 0; i < cap; i++) {
            maxHeap.push_back(Elem(nums[i], maxSeq));
            seq2HeapIdx[maxSeq] = i;
            maxSeq++;
        }

        buildHeap();
    }
public:
    int max() {
        return maxHeap[0].val;
    }

    void add(int val) {
        int kickoffSeq = maxSeq - capacity;
        auto iter = seq2HeapIdx.find(kickoffSeq);
        assert(iter != seq2HeapIdx.end());
        int idx = iter->second;
        Elem elem(val, maxSeq);
        maxHeap[idx] = elem;
        seq2HeapIdx[maxSeq] = idx;
        seq2HeapIdx.erase(iter);

        siftUp(idx);
        siftDown(idx);
        maxSeq++;
    }
private:
    void buildHeap() {
        for (int i = capacity/2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }
    void siftDown(int i) {
        int left = leftChild(i);
        if (left >= capacity) {
            return;
        }
        int maxChild = left;
        int right = left + 1;
        if (right < capacity && maxHeap[right].val > maxHeap[left].val) {
            maxChild = right;
        }
        if (maxHeap[i].val < maxHeap[maxChild].val) {
            this->swap(i, maxChild);
            siftDown(maxChild);
        }
    }

    void swap(int i, int j) {
        seq2HeapIdx[maxHeap[i].seq] = j;
        seq2HeapIdx[maxHeap[j].seq] = i;
        std::swap(maxHeap[i], maxHeap[j]);
    }

    void siftUp(int i) {
        if (i <= 0) {
            return;
        }
        int father = parent(i);

        if (maxHeap[father].val < maxHeap[i].val) {
            this->swap(father, i);
            siftUp(father);
        }
    }

    int leftChild(int i) {
        return i*2+1;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }
private:
    vector<Elem> maxHeap;
    map<int, int> seq2HeapIdx; 
    int capacity;
    int maxSeq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        vector<int> result;
        // corner case
        if (nums.size() == 0) {
            return result;
        }

        HeapSorter maxSW(nums, k);
        
        
        for (int i = k; i < nums.size(); i++) {
            result.push_back(maxSW.max());
            maxSW.add(nums[i]);
        }
        result.push_back(maxSW.max());

        return result;
    }

};
