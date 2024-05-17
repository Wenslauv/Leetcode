/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>


namespace leetcode {

    void setZeroes(std::vector<std::vector<int>>& matrix) {
        const auto rows     = std::size(matrix);
        const auto columns  = std::size(matrix.front());
        
        bool firstRowHasZeroes      = false;
        bool firstColumnHasZeroes   = false;

        for (int i = 0; i < columns; ++i) {
            if (matrix[0][i] == 0) {
                firstRowHasZeroes = true;
                break;
            }
        }

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                firstColumnHasZeroes = true;
                break;
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                if (matrix[0][j] == 0 or matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowHasZeroes) {
            for (int i = 0; i < columns; ++i) {
                matrix[0][i] = 0;
            }
        }

        if (firstColumnHasZeroes) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }


    namespace testing {
        
        using Matrix_t = std::vector<std::vector<int>>;

        void test1() {
            Matrix_t matrix {
                {1,1,1},
                {1,0,1},
                {1,1,1}
            };

            Matrix_t expected {
                {1,0,1},
                {0,0,0},
                {1,0,1}
            };

            setZeroes(matrix);
            assert(matrix == expected);
        }

        void test2() {
            Matrix_t matrix {
                {0,1,2,0},
                {3,4,5,2},
                {1,3,1,5}
            };

            Matrix_t expected {
                {0,0,0,0},
                {0,4,5,0},
                {0,3,1,0}
            };

            setZeroes(matrix);
            assert(matrix == expected);

        }


        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
