/**
 *
 * \file
 * \brief [Ransom Note](https://leetcode.com/problems/ransom-note/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed by using the letters from `magazine` and `false` otherwise.
 *
 * Each letter in `magazine` can only be used once in `ransomNote`.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= ransomNote.length, magazine.length <= 10^5`
 *      `ransomNote` and `magazine` consist of lowercase English letters.
 */


#include <cassert>
#include <iostream>
#include <string>

#include <doctest/doctest.h>


namespace leetcode::ransom_note {

    bool canConstruct(std::string ransomNote, std::string magazine) {
        int frequency[26] = {0};

        for (const char& c : magazine)
            frequency[ c - 'a' ] ++;

        for (const char& c : ransomNote) {
            if (frequency[ c - 'a'] <= 0)
                return false;
            
            frequency[ c - 'a'] --;
        }

        return true;
    }



    namespace testing {

        TEST_CASE("0383. Ransom Note") {

            SUBCASE("test 1") {
                CHECK( canConstruct( "a", "b") == false);
            }


            SUBCASE("test 2") {
                CHECK( canConstruct( "aa", "ab") == false);
            }


            SUBCASE("test 3") {
                CHECK( canConstruct( "aa", "aab") == true);
            }

        }
    }   // namespace testing

}   // namespace leetcode::ransom_note
