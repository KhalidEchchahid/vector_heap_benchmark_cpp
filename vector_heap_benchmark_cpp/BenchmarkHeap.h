#pragma once
#include <vector>
#include <queue>
#include <chrono>
#include <iostream>

class BenchmarkHeap {
private:
    static const int SIZE = 10000000; // Size of the data structure
    std::vector<int> vec;           // std::vector for testing
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap; // Min-heap

public:
    void fillVector();              // Fill the vector
    void fillHeap();                // Fill the heap

    bool searchVector(int target);  // Search in the vector
    bool searchHeap(int target);    // Search in the heap

    void runBenchmark();            // Run and display benchmark results
};
