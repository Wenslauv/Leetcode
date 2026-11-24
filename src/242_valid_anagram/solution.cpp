/**
 *
 * \file
 * \brief [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 *
 *
 * <h4>Constrains</h4>
 *      1 <= s.length, t.length <= 5 * 10^4
 *      s and t consist of lowercase English letters.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

#include <doctest/doctest.h>


namespace leetcode::valid_anagram {

    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> counts {};

        for (auto symbol : s) {
            counts[symbol] ++;
        }

        for (auto symbol : t) {
            counts[symbol] --;
        }

        for (const auto& [key, value] : counts) {
            if (value != 0)
                return false;
        }

        return true;
    }


    namespace testing {

        TEST_CASE("0242. Valid Anagram") {

            SUBCASE("test 1") {
                CHECK( isAnagram("anagram", "nagaram") == true );
            }


            SUBCASE("test 2") {
                CHECK( isAnagram("rat", "car") == false );
            }

        }
    }   // namespace testing

}   // namespace leetcode::valid_anagram
