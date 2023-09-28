#ifndef CALC_HPP
#define CALC_HPP

#include <vector>

class ParallelMatrixCalculator {

public:
    bool checkMultiplicationPossible(
        const std::vector<std::vector<int>>& A,
        const std::vector<std::vector<int>>& B
    );

    void matrixMultiply(
        const std::vector<std::vector<int>>& A,
        const std::vector<std::vector<int>>& B,
        std::vector<std::vector<int>>& R,
        int startRow,
        int endRow
    );

    void parallelMatrixMultiply(
        const std::vector<std::vector<int>>& A,
        const std::vector<std::vector<int>>& B,
        std::vector<std::vector<int>>& R,
        int numThreads
    );

};

#endif