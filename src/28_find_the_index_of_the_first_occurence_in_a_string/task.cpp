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


namespace leetcode {

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

        void test1() {
            assert( strStr("sadbutsad", "sad") == 0 );
        }

        void test2() {
            assert( strStr("leetcode", "leeto") == -1 );
        }

        void test3() {
            assert( strStr("saadbutsad", "sad") == 7 );
        }

        void test4() {
            assert( strStr("a", "a") == 1 );
        }

        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
