/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>

#include <doctest/doctest.h>


namespace leetcode::rotate_image {

    void rotate(std::vector<std::vector<int>>& matrix) {
        const auto count = std::ssize(matrix);

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap( matrix[i][j], matrix[j][i] );
            }
        }

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count/2; ++j ) {
                std::swap( matrix[i][j], matrix[i][count - j - 1]);
            }
        }
    }


    namespace testing {

        
        using Matrix_t = std::vector<std::vector<int>>;

        TEST_CASE("0048. Rotate Image") {

            SUBCASE("test 1") {
                Matrix_t matrix {
                    {1,2,3},
                    {4,5,6},
                    {7,8,9},
                };

                Matrix_t expected {
                    {7, 4, 1},
                    {8, 5, 2},
                    {9, 6, 3},
                };

                rotate(matrix);
                CHECK(matrix == expected);
            }


            SUBCASE("test 2") {
                Matrix_t matrix {
                    {5,1,9,11},
                    {2,4,8,10},
                    {13,3,6,7},
                    {15,14,12,16},
                };

                Matrix_t expected {
                    {15,13,2,5},
                    {14,3,4,1},
                    {12,6,8,9},
                    {16,7,10,11}
                };

                rotate(matrix);
                CHECK(matrix == expected);
            }

        }
    }   // namespace testing

}   // namespace leetcode::rotate_image
