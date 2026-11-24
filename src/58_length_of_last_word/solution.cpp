/**
 *
 * \file
 * \brief [Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * <h4>Constrains</h4>
 *      1 <= s.length <= 10^4
 *      s consists of only English letters and spaces '  '.
 *      There will be at least one word in s.
 */


#include <cassert>
#include <iostream>
#include <string>

#include <doctest/doctest.h>


namespace leetcode::length_of_last_word {

    int lengthOfLastWord(std::string s) {
        auto last = std::prev(std::end(s));
        auto first = std::begin(s);

        while (*last == ' ') {
            last = std::prev(last);
        }

        int wordSize = 0;

        while (*last != ' ' and last >= first){
            wordSize ++;
            last = std::prev(last);
        }

        return wordSize;
    }


    namespace testing {

        TEST_CASE("0058. Length of Last Word") {

            SUBCASE("test 1") {
                CHECK( lengthOfLastWord("Hello World") == 5 );
            }


            SUBCASE("test 2") {
                CHECK( lengthOfLastWord("   fly me   to   the moon  ") == 4 );
            }


            SUBCASE("test 3") {
                CHECK( lengthOfLastWord("luffy is still joyboy") == 6 );
            }


            SUBCASE("test 4") {
                CHECK( lengthOfLastWord("a") == 1 );
            }

        }
    }   // namespace testing

}   // namespace leetcode::length_of_last_word
