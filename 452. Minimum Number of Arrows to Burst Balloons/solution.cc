class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
       if (points.size() == 0) {
           return 0;
       }
       vector<LineSegmentPoint> segmentPoints;
       segmentPoints.reserve(points.size() * 2);
       for (int i = 0; i < points.size(); i++) {
           segmentPoints.push_back(makeStart(i, points[i].first));
           segmentPoints.push_back(makeEnd(i, points[i].second));
       }
       sort(segmentPoints.begin(), segmentPoints.end(), SegmentPointSorter());

       int shots = 0;
       set<int> burstedBalloons;
       vector<int> visited;
       for (auto iter = segmentPoints.begin(); iter != segmentPoints.end(); iter++) {
           if (iter->isStart()) {
               visited.push_back(iter->id_);
               continue;
           }
           int id = iter->id_;
           if (burstedBalloons.count(id) > 0) {
               continue;
           }
           shots += 1;
           for (int i = 0; i < visited.size(); i++) {
               burstedBalloons.insert(visited[i]);
           }
           visited.clear();
       }
       return shots;
    }
   
private:
    enum class PointType {Start = 0, End = 1};
    struct LineSegmentPoint {
        PointType type_;
        int id_;
        int x_;
        LineSegmentPoint(PointType type, int id, int x): type_(type), id_(id), x_(x) {}
        bool isStart() const {
            return type_ == PointType::Start;
        }
    };
    LineSegmentPoint makeStart(int id, int x) {
        return LineSegmentPoint(PointType::Start, id, x);
    }
    LineSegmentPoint makeEnd(int id, int x) {
        return LineSegmentPoint(PointType::End, id, x);
    }
    struct SegmentPointSorter {
        bool operator() (const LineSegmentPoint &lhs, const LineSegmentPoint &rhs) {
            if (lhs.x_ < rhs.x_ || (lhs.x_ == rhs.x_ && (int)lhs.type_ < (int)rhs.type_)) {
                return true;
            }
            return false;
        }
    };
};


