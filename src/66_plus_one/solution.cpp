/**
 *
 * \file
 * \brief [Plus One](https://leetcode.com/problems/plus-one/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 *
 * <h4>Constrains</h4>
 *      1 <= digits.length <= 100
 *      0 <= digits[i] <= 9
 *      digits does not contain any leading 0's.
 */


#include <cassert>
#include <iostream>

#include <doctest/doctest.h>


namespace leetcode::plus_one {

    std::vector<int> plusOne(std::vector<int>& digits) {
        const int size = static_cast<int>(digits.size());

        std::vector<int> result(size + 1);

        result[size] = digits[size-1] + 1;
        bool passed = result[size] > 9;
        result[size] %= 10;


        for (int i = size-2; i >=0 ; --i) {
            result[i + 1] = digits[i] + (int)passed;
            passed = result[i + 1] > 9;
            result[i+1] %= 10;
        }

        if (passed) {
            result[0] = 1;
            return result;
        }

        return { std::next(result.begin()), result.end() };
    }


    namespace testing {

        TEST_CASE("0066. Plus One") {

            SUBCASE("test 1") {
                std::vector<int> digits {1, 2, 3};
                CHECK( (plusOne( digits ) == std::vector<int>{ 1, 2, 4 }) );
            }


            SUBCASE("test 2") {
                std::vector<int> digits {4, 3, 2, 1};
                CHECK( (plusOne( digits ) == std::vector<int>{ 4, 3, 2, 2 }) );
            }


            SUBCASE("test 3") {
                std::vector<int> digits {9};
                CHECK( (plusOne( digits ) == std::vector<int>{ 1, 0}) );
            }

        }
    }   // namespace testing

}   // namespace leetcode::plus_one
