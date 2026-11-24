/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>

#include <doctest/doctest.h>


namespace leetcode::set_matrix_zeroes {

    void setZeroes(std::vector<std::vector<int>>& matrix) {
        const auto rows     = std::ssize(matrix);
        const auto columns  = std::ssize(matrix.front());
        
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

        TEST_CASE("0073. Set Matrix Zeroes") {

            SUBCASE("test 1") {
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
                CHECK(matrix == expected);
            }


            SUBCASE("test 2") {
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
                CHECK(matrix == expected);
            }

        }
    }   // namespace testing

}   // namespace leetcode::set_matrix_zeroes
