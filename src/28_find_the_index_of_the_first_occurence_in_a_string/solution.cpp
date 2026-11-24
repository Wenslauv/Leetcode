/**
 *
 * \file
 * \brief [Find the Index of the First Occurence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= haystack.length, needle.length <= 10^4`
 *      `haystack` and `needle` consist of only lowercase English characters.
 */


#include <cassert>
#include <iostream>
#include <string>

#include <doctest/doctest.h>


namespace leetcode::find_the_index_of_the_first_occurrence_in_a_string {

    int strStr(std::string haystack, std::string needle) {
        int overallLength = static_cast<int>( haystack.size() ) - static_cast<int>( needle.size() ) + 1;

        for (int i = 0; i < overallLength; ++i) {
            if (needle[0] == haystack[i]) {
                bool wholeWordFound = true;

                for (int j = 1; j < needle.size(); ++j) {
                    if (needle[j] != haystack[i + j]) {
                        wholeWordFound = false;
                        break;
                    }
                }

                if (wholeWordFound)
                    return i;
            }
        }

        return -1;
    }


    namespace testing {

        TEST_CASE("0028. Find the Index of the First Occurrence in a String") {

            SUBCASE("test 1") {
                CHECK( strStr("sadbutsad", "sad") == 0 );
            }


            SUBCASE("test 2") {
                CHECK( strStr("leetcode", "leeto") == -1 );
            }


            SUBCASE("test 3") {
                CHECK( strStr("saadbutsad", "sad") == 7 );
            }


            SUBCASE("test 4") {
                CHECK( strStr("a", "a") == 1 );
            }

        }
    }   // namespace testing

}   // namespace leetcode::find_the_index_of_the_first_occurrence_in_a_string
