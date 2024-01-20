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


namespace leetcode {

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        if (strs.size() == 1)
            return strs.front();

        int size            = static_cast<int>( strs.size() );
        std::string prefix  = strs.front();

        for (int i = 1; i < size; ++i) {
            auto& current = strs[i];

            if (current.size() < prefix.size()) {
                prefix.resize( current.size() );
            }

            int prefixSize = static_cast<int>( prefix.size() );
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

        void test1(void) {
            std::vector<std::string> strs = { "flower","flow","flight" };
            assert( longestCommonPrefix(strs) == "fl" );
        }

        void test2() {
            std::vector<std::string> strs = { "dog","racecar","car" };
            assert( longestCommonPrefix(strs) == "" );
        }

        void test3() {
            std::vector<std::string> strs = { "ab","a" };
            assert( longestCommonPrefix(strs) == "a" );
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
