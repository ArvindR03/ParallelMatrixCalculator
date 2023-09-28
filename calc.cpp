#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include "calc.hpp"


void main() {



};

// function to check if matrix multiplication is possible
bool ParallelMatrixCalculator::checkMultiplicationPossible(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B
) {

    if (A[0].size() == B.size()) {
        return true;
    } else {
        return false;
    }

};

// function to do matrix multiplication for a given row range
void ParallelMatrixCalculator::matrixMultiply(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B,
    std::vector<std::vector<int>>& R,
    int startRow,
    int endRow
) {

    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < B[0].size(); j++) {

            R[i][j] = 0;
            for (int k = 0; k < A[0].size(); k++) {
                R[i][j] += A[i][k] * B[k][j];
            };

        };
    };

};

// function to to full multiplication with parallel processing
void ParallelMatrixCalculator::parallelMatrixMultiply(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B,
    std::vector<std::vector<int>>& R,
    int numThreads
) {

    int rows = A.size();
    int rowsPerThread = std::ceil(static_cast<double>(rows / numThreads));

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {

        int startRow = i * rowsPerThread;
        int endRow = (i + 1) * rowsPerThread;

        if (endRow >= A.size()) {
            endRow = A.size() - 1;
        };

        threads.emplace_back(matrixMultiply, std::ref(A), std::ref(B), std::ref(R), startRow, endRow);

    };

    for (std::thread& thread : threads) {
        thread.join();
    };


};