class MyComparator {
    public:
        bool operator()(pair<int, int> e1, pair<int, int> e2) {
            if(e1.first > e2.first){
                return true;
            }
            if(e1.first == e2.first){
                if(e1.second >= e2.second){
                    return true;
                }
            }
            return false;
        }
};
// min heap
priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparator> minHeap;
