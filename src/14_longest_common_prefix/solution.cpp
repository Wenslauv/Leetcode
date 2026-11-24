/**
 *
 * \file
 * \brief [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * <h4>Constrains</h4>
 *      1 <= strs.length <= 200
 *      0 <= strs[i].length <= 200
 *      strs[i] consists of only lowercase English letters.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include <doctest/doctest.h>


namespace leetcode::longest_common_prefix {

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        if (strs.size() == 1)
            return strs.front();

        const int size      = std::ssize(strs);
        std::string prefix  = strs.front();

        for (int i = 1; i < size; ++i) {
            auto& current = strs[i];

            if (current.size() < prefix.size()) {
                prefix.resize( current.size() );
            }

            const int prefixSize = std::ssize(prefix);
            for (int j = 0; j < prefixSize; ++j) {

                if (prefix[j] != current[j]) {
                    prefix.resize( j );
                    break;
                }

            }
        }

        return prefix;
    }


    namespace testing {

        TEST_CASE("0014. Longest Common Prefix") {

            SUBCASE("test 1") {
                std::vector<std::string> strs = { "flower","flow","flight" };
                CHECK( longestCommonPrefix(strs) == "fl" );
            }


            SUBCASE("test 2") {
                std::vector<std::string> strs = { "dog","racecar","car" };
                CHECK( longestCommonPrefix(strs) == "" );
            }


            SUBCASE("test 3") {
                std::vector<std::string> strs = { "ab","a" };
                CHECK( longestCommonPrefix(strs) == "a" );
            }

        }
    }   // namespace testing

}   // namespace leetcode::longest_common_prefix
