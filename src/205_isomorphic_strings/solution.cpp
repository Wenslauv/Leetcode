/**
 *
 * \file
 * \brief [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given two strings `s` and `t`, determine if they are isomorphic.
 *
 * Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= s.length <= 5 * 10^4`
 *      `t.length == s.length`
 *      `s` and `t` consist of any valid ascii character.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

#include <doctest/doctest.h>


namespace leetcode::isomorphic_strings {

    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> subsTable {};

        int size = std::ssize(s);

        for (int i = 0; i < size; ++i) {
            const char& symbol = s[i];

            if (subsTable.count( symbol) ) {
                const auto& sub = subsTable[symbol];

                if (t[i] != sub)
                    return false;

                t[i] = symbol;
            }
            else {
                const auto subSymbol = t[i];

                for (const auto& [key, value] : subsTable) {
                    if (value == subSymbol)
                        return false;
                }

                t[i] = symbol;

                subsTable[symbol] = subSymbol;
            }
        }

        return s == t;
    }


    namespace testing {

        TEST_CASE("0205. Isomorphic Strings") {

            SUBCASE("test 1") {
                CHECK( isIsomorphic("egg", "add") == true );
            }


            SUBCASE("test 2") {
                CHECK( isIsomorphic("foo", "bar") == false );
            }


            SUBCASE("test 3") {
                CHECK( isIsomorphic("paper", "title") == true );
            }


            SUBCASE("test 4") {
                CHECK( isIsomorphic("badc", "baba") == false );
            }


            SUBCASE("test 5") {
                CHECK( isIsomorphic("egcd", "adfd") == false );
            }

        }
    }   // namespace testing

}   // namespace leetcode::isomorphic_strings
