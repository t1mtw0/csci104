#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T> class MaxHeap {
  private:
    std::vector<T> data;

  public:
    void push(const T &item);
    // Removes the largest element in the heap
    void pop();
    // Returns the largest element in the heap (but does not remove it)
    T const &top() const;
    std::size_t size() const;
};

template <typename T> void MaxHeap<T>::push(const T &item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / 2;
        T &current = data[index];
        T &parent = data[parent_index];
        if (current <= parent) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
    }
}

template <typename T> void MaxHeap<T>::pop() {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }

    // TO BE COMPLETETED
    std::swap(data[0], data[data.size() - 1]);
    data.pop_back();
    std::size_t index = 0;
    while (index < data.size()) {
        std::size_t largest = index;
        std::size_t left_i = index * 2 + 1;
        std::size_t right_i = index * 2 + 2;
        if (left_i < data.size() && data[left_i] > data[largest])
            largest = left_i;
        if (right_i < data.size() && data[right_i] > data[largest])
            largest = right_i;
        if (largest != index) {
            std::swap(data[largest], data[index]);
            index = largest;
        } else {
            break;
        }
    }
}

template <typename T> T const &MaxHeap<T>::top() const {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }
    return data[0];
}

template <typename T> std::size_t MaxHeap<T>::size() const {
    return data.size();
}
