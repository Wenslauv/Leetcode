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


namespace leetcode {

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

        void test1() {
            std::vector<std::string> strs {"eat","tea","tan","ate","nat","bat"};
            std::vector<std::vector<std::string>> expected {
                { "bat" }, { "tan", "nat"},{"eat","tea", "ate"}
            };

            auto result = groupAnagrams(strs);
            assert(result == expected);
        }

        void test2() {
            std::vector<std::string> strs {"a"};
            std::vector<std::vector<std::string>> expected {
                {"a"}
            };

            auto result = groupAnagrams(strs);
            assert(result == expected);
        }

        void test3() {
            std::vector<std::string> strs {""};
            std::vector<std::vector<std::string>> expected {
                {""}
            };

            auto result = groupAnagrams(strs);
            assert(result == expected);
        }


        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();
            test3();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
