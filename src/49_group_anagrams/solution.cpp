/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <doctest/doctest.h>


namespace leetcode::group_anagrams {

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> hashmap {};

        for (const auto& str : strs) {
            auto key = str;
            std::sort(std::begin(key), std::end(key));

            hashmap[ key ].push_back(str);
        }

        std::vector<std::vector<std::string>> result {};
        result.reserve( std::size(hashmap) );
        for (const auto& [key, values] : hashmap) {
            result.push_back(values);
        }

        return result;
    }


    namespace testing {

        TEST_CASE("0049. Group Anagrams") {

            SUBCASE("test 1") {
                std::vector<std::string> strs {"eat","tea","tan","ate","nat","bat"};
                std::vector<std::vector<std::string>> expected {
                    { "bat" }, { "tan", "nat"},{"eat","tea", "ate"}
                };

                auto result = groupAnagrams(strs);
                CHECK(result == expected);
            }


            SUBCASE("test 2") {
                std::vector<std::string> strs {"a"};
                std::vector<std::vector<std::string>> expected {
                    {"a"}
                };

                auto result = groupAnagrams(strs);
                CHECK(result == expected);
            }


            SUBCASE("test 3") {
                std::vector<std::string> strs {""};
                std::vector<std::vector<std::string>> expected {
                    {""}
                };

                auto result = groupAnagrams(strs);
                CHECK(result == expected);
            }

        }
    }   // namespace testing

}   // namespace leetcode::group_anagrams
