#include "stones.h"
#include "max_heap.h"

int lastStoneWeight(std::vector<int>& stones) {
    MaxHeap<int> heap;
    
    // TO BE COMPLETED
    for (int s: stones) {
        heap.push(s);
    }
    while (heap.size() > 1) {
        int y = heap.top();
        heap.pop();
        int x = heap.top();
        heap.pop();
        if (x != y) {
            y = y - x;
            heap.push(y);
        }
    }
    if (heap.size() == 0) return 0;
    return heap.top();
}
