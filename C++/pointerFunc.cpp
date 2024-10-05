#include <iostream>
#include <utility>
#include <functional>
#include <vector>

// Comparator for ascending order
bool ascending(int x, int y) {
    return x < y;  // Corrected logic
}

// Comparator for descending order
bool descending(int x, int y) {
    return x > y;  // Corrected logic
}

// Selection sort function with a comparator
void selectionSort(int *array, int size, std::function<bool(int, int)> comp = descending) {
    for (int startIndex = 0; startIndex < (size - 1); ++startIndex) {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
            if (comp(array[smallestIndex], array[currentIndex])) {
                smallestIndex = currentIndex;
            }
        }

        std::swap(array[startIndex], array[smallestIndex]);
    }
}

int main() {
    std::vector<int> array{4, 2, 1, 5, 3}; // Using vector for dynamic size

    // Sort in ascending order
    selectionSort(array.data(), array.size(), ascending); // Passing data() to get the raw pointer

    std::cout << "Sorted array in ascending order:\n";
    for (const int &value : array) {
        std::cout << value << '\n';
    }

    return 0;
}
