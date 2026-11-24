/**
 *
 * \file
 * \brief [Palindrome Number](https://leetcode.com/problems/palindrome-number/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * <h4>Constrains</h4>
 *      -231 <= x <= 231 - 1
 */


#include <vector>
#include <cassert>
#include <iostream>

#include <doctest/doctest.h>


namespace leetcode::palindrome_number {
    
    bool isPalindrome(int x) {
            if (x < 0)
                return false;

            long int reversed = 0;
            long int origin = x;

            while (x != 0) {
                reversed = reversed * 10 + x % 10;
                x /= 10;
            }

            return (reversed == origin);
        }



    namespace testing {

        TEST_CASE("0009. Palindrome Number") {

            SUBCASE("test 1") {
                CHECK( isPalindrome(121) == true );
            }


            SUBCASE("test 2") {
                CHECK( isPalindrome(-121) == false );
            }


            SUBCASE("test 3") {
                CHECK( isPalindrome(10) == false );
            }

        }
    }   // namespace testing

}   // namespace leetcode::palindrome_number
