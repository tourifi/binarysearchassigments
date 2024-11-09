#include <iostream>
#include <array>
#include <vector>


template <typename T, size_t N>
int binarySearch(const std::array<T, N>& arr, T target) {
    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


template <typename T>
int binarySearch(const std::vector<T>& vec, T target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


template <typename T, size_t N>
int binarySearchFirst(const std::array<T, N>& arr, T target) {
    int index = binarySearch(arr, target);
    if (index == -1) return -1; 

    while (index > 0 && arr[index - 1] == target) {
        index--;
    }
    return index;
}
template <typename T>
int binarySearchFirst(const std::vector<T>& vec, T target) {
    int index = binarySearch(vec, target);
    if (index == -1) return -1; 

    while (index > 0 && vec[index - 1] == target) {
        index--;
    }
    return index;
}

int main() {
    std::vector<int> vec = {10, 20, 30, 30, 30, 40, 50, 60, 70, 70}; 
    int target;

    std::cout << "Enter the value of target: ";
    std::cin >> target;

    int index = binarySearchFirst(vec, target);
    if (index != -1) {
        std::cout << "Binary search (first). Element found at index: " << index << std::endl;
    } else {
        std::cout << "Binary search (first). Element not found in the vector." << std::endl;
    }

    std::array<int, 10> arr = {10, 20, 30, 30, 30, 40, 50, 60, 70, 70}; q
    index = binarySearchFirst(arr, target);
    if (index != -1) {
        std::cout << "Binary search (first). Element found at index: " << index << std::endl;
    } else {
        std::cout << "Binary search (first). Element not found in the array." << std::endl;
    }

    return 0;
}
