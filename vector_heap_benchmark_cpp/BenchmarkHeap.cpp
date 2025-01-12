#include "BenchmarkHeap.h"

void BenchmarkHeap::fillVector() {
    vec.reserve(SIZE); // Reserve memory to avoid reallocations
    for (int i = 0; i < SIZE; ++i) {
        vec.push_back(i);
    }
}

void BenchmarkHeap::fillHeap() {
    for (int i = 0; i < SIZE; ++i) {
        heap.push(i);
    }
}

bool BenchmarkHeap::searchVector(int target) {
    for (const int& value : vec) {
        if (value == target) {
            return true;
        }
    }
    return false; // Worst case: target not found
}

bool BenchmarkHeap::searchHeap(int target) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> tempHeap = heap; // Copy heap
    while (!tempHeap.empty()) {
        if (tempHeap.top() == target) {
            return true;
        }
        tempHeap.pop();
    }
    return false; // Worst case: target not found
}

void BenchmarkHeap::runBenchmark() {
    using namespace std::chrono;

    // Benchmark filling std::vector
    auto start = high_resolution_clock::now();
    fillVector();
    auto end = high_resolution_clock::now();
    auto durationVectorFill = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time to fill std::vector: " << durationVectorFill << " ms" << std::endl;

    // Benchmark filling heap
    start = high_resolution_clock::now();
    fillHeap();
    end = high_resolution_clock::now();
    auto durationHeapFill = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time to fill heap: " << durationHeapFill << " ms" << std::endl;

    // Benchmark search in std::vector
    int target = SIZE + 1; // Worst case: target not found
    start = high_resolution_clock::now();
    searchVector(target);
    end = high_resolution_clock::now();
    auto durationVectorSearch = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time to search in std::vector: " << durationVectorSearch << " ms" << std::endl;

    // Benchmark search in heap
    start = high_resolution_clock::now();
    searchHeap(target);
    end = high_resolution_clock::now();
    auto durationHeapSearch = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time to search in heap: " << durationHeapSearch << " ms" << std::endl;
}
