/**
 *
 * \file
 * \brief [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * <h4>Constrains</h4>
 *      1 <= s.length <= 2 * 105
 *      s consists only of printable ASCII characters.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <cctype>

#include <doctest/doctest.h>


namespace leetcode::valid_palindrome {

    bool isPalindrome(std::string s) {
        int front = 0;
        int back = static_cast<int>(s.length()) - 1;

        while (front <= back) {
            if (not std::isalnum(s[front])) {
                front++;
                continue;
            }

            if (not std::isalnum(s[back])) {
                back --;
                continue;
            }

            if (std::tolower(s[front]) != std::tolower(s[back]))
                return false;

            front ++;
            back --;
        }

        return true;
    }


    namespace testing {

        TEST_CASE("0125. Valid Palindrome") {

            SUBCASE("test 1") {
                CHECK( isPalindrome( "A man, a plan, a canal: Panama" ) == true );
            }


            SUBCASE("test 2") {
                CHECK( isPalindrome( "race a car" ) == false );
            }


            SUBCASE("test 3") {
                CHECK( isPalindrome( " " ) == true );
            }

        }
    }   // namespace testing

}   // namespace leetcode::valid_palindrome
