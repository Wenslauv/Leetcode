/**
 *
 * \file
 * \brief [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
 *
 *
 * <h4>Constrains</h4>
 *      0 <= n <= 10^4
 */


#include <cassert>
#include <iostream>

#include <doctest/doctest.h>


namespace leetcode::factorial_trailing_zeroes {

    int trailingZeroes(int n) {
        int count {};

        while (n / 5 > 0) {
            count += n / 5;
            n /= 5;
        }

        return count;
    }


    namespace testing {

        TEST_CASE("0172. Factorial Trailing Zeroes") {

            SUBCASE("test 1") {
                CHECK( trailingZeroes(3) == 0 );
            }


            SUBCASE("test 2") {
                CHECK( trailingZeroes(5) == 1 );
            }


            SUBCASE("test 3") {
                CHECK( trailingZeroes(0) == 0 );
            }

        }
    }   // namespace testing

}   // namespace leetcode::factorial_trailing_zeroes
