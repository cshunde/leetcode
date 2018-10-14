class ExamRoom {
private:
    class SeatInterval {
    public:
        SeatInterval(ExamRoom *examRoom, int left, int right): left_(left), right_(right), examRoom_(examRoom) {}
        SeatInterval(const SeatInterval&) = default;
        SeatInterval& operator= (const SeatInterval& other) {
            examRoom_ = other.examRoom_;
            left_ = other.left_;
            right_ = other.right_;
            return *this;
        }
        int seat() const {
            if (left_ == -1) {
                return 0;
            } else if (right_ == examRoom_->seatsNum_) {
                return examRoom_->seatsNum_ - 1;
            }
            return right_ - (right_ - left_ + 1) / 2;
        }
        int interval() const {
            if (left_ == -1 || right_ == examRoom_->seatsNum_)  {
                return (right_ - left_ - 1) - 1;
            }
            return seat() - left_ - 1;
        }
        int left() const {
            return left_;
        }
        int right() const {
            return right_;
        }
    private:
        ExamRoom *examRoom_;
        int left_;
        int right_;
        int interval_;
    };
    class Compare {
    public:
        bool operator() (const SeatInterval &lhs, const SeatInterval &rhs) {
            return (lhs.interval() < rhs.interval()  || (lhs.interval() == rhs.interval() && lhs.left() >= rhs.left()));
        }
    };
public:
    ExamRoom(int N) {
        seatsNum_ = N;
        studentsNum_ = 0;
        maxHeap_.push_back(SeatInterval(this, -1, N));
    }
    
    int seat() {
        if (studentsNum_ == seatsNum_) {
            return -1;
        }
        SeatInterval oldSeatInterval = maxHeap_.front();
        maxHeap_.erase(maxHeap_.begin());
        studentsNum_++;
        
        int seatPos = oldSeatInterval.seat();
        maxHeap_.push_back(SeatInterval(this, oldSeatInterval.left(), seatPos));
        maxHeap_.push_back(SeatInterval(this, seatPos, oldSeatInterval.right()));

        std::make_heap(maxHeap_.begin(), maxHeap_.end(), Compare());
        
        return seatPos;
    }
    

    void leave(int p) {
        auto leftIter = std::find_if(maxHeap_.begin(), maxHeap_.end(), [=](const SeatInterval &seatInterval) {
            return seatInterval.right() == p;
        });
        int left = leftIter->left();
        maxHeap_.erase(leftIter);
        
        auto rightIter = std::find_if(maxHeap_.begin(), maxHeap_.end(), [=](const SeatInterval &seatInterval) {
            return seatInterval.left() == p;
        });
        int right = rightIter->right();
        maxHeap_.erase(rightIter);
        
        maxHeap_.push_back(SeatInterval(this, left, right));
        
        std::make_heap(maxHeap_.begin(), maxHeap_.end(), Compare());
        studentsNum_--;
    }
private:
    int seatsNum_;
    int studentsNum_;
    std::vector<SeatInterval> maxHeap_;
};

