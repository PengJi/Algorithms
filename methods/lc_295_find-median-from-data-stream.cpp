/**
 * 295. 数据流的中位数
 * https://leetcode-cn.com/problems/find-median-from-data-stream/
 */

class MedianFinder {
public:
    // 建立一个大根堆，一个小根堆。大根堆存储小于当前中位数，小根堆存储大于等于当前中位数，且大根堆中的数字个数永远都比小根堆多 1 或相等。
    // 根据上述定义，我们每次可以通过大根堆的堆顶或者两个堆的堆顶元素的平均数求出中位数。
    // 维护时，如果新加入的元素小于等于大根堆的堆顶，则加入大根堆；否则加入小根堆。
    // 然后如果发现两个堆的大小关系不满足上述要求，则可以通过弹出一个堆的元素放到另一个堆中。
    priority_queue<int> smaller;                            // 大根堆
    priority_queue<int, vector<int>, greater<int>> larger;  // 小根堆

    MedianFinder() {
    }

    void addNum(int num) {
        if (smaller.empty() || num <= smaller.top()) {
            smaller.push(num);
            if (smaller.size() > larger.size() + 1) {
                larger.push(smaller.top());
                smaller.pop();
            }
        } else {
            larger.push(num);
            if (larger.size() > smaller.size()) {
                smaller.push(larger.top());
                larger.pop();
            }
        }
    }

    double findMedian() {
        if ((larger.size() + smaller.size()) % 2 == 0) {
            return (larger.top() + smaller.top()) / 2.0;
        } else {
            return smaller.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */