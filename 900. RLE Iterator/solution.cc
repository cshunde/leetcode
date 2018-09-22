class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        int64_t cnt = 0;
        nums.reserve(A.size()/2);
        accus.reserve(A.size()/2);
        for (int i = 0; i < A.size(); i+=2) {
            cnt += A[i];
            if (A[i]!=0) {
                nums.push_back(A[i+1]);
                accus.push_back(cnt);
            }
        }
        amount = cnt;
    }
    
    int next(int n) {
       currPos += n;
       if (currPos > amount) {
           return -1;
       }
       auto iter = std::lower_bound(accus.begin(), accus.end(), currPos);
       if (iter == accus.end()) {
           return -1;
       }
       auto retIter = nums.begin();
       std::advance(retIter, std::distance(accus.begin(), iter));
       return *retIter;
    }
private:
    int64_t currPos = 0;
    int64_t amount = 0;
    std::vector<int> nums;
    std::vector<int64_t> accus;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
