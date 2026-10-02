class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>,greater<int>> minHeap;
    double median;
    MedianFinder() {
        median = 0 ;
    }
    
    void addNum(int num) {
        // 3 cases
        if(maxHeap.size()==minHeap.size()){
            if(num > median){
                // insert in right
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                // insert in left
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if(maxHeap.size()==minHeap.size()+1){
            if(num > median){
                // insert in minHeap
                minHeap.push(num);
            }
            else{
                // insert in maxHeap
                int front = maxHeap.top();
                maxHeap.pop();

                minHeap.push(front);
                maxHeap.push(num);
            }
            median = (minHeap.top()+maxHeap.top())/2.0;
        }
        else if(maxHeap.size()+1==minHeap.size()){
            if(num > median){
                // insert in minHeap
                int front = minHeap.top();
                minHeap.pop();

                minHeap.push(num);
                maxHeap.push(front);

            }
            else{   
                // insert in maxHeap
                maxHeap.push(num);
            }
            median = (minHeap.top()+maxHeap.top())/2.0;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */