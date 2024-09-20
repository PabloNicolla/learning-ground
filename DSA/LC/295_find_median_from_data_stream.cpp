#include <queue>
#include <vector>

class MedianFinder
{
    std::priority_queue<int> maxHeap{};
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap{};
    int size{};

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        minHeap.push(num);
        ++size;
        if (size == 1)
        {
            return;
        }
        else if (size % 2 == 0)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (minHeap.top() < maxHeap.top())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if (size % 2 == 0)
        {
            return static_cast<double>(minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            return minHeap.top();
        }
    }
};

int main()
{
    MedianFinder medianFinder = MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.findMedian(); // return 1.0
    medianFinder.addNum(3);    // arr = [1, 3]
    medianFinder.findMedian(); // return 2.0
    medianFinder.addNum(2);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0
    return 0;
}