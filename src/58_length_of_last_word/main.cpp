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


namespace leetcode {

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

        void test1(void) {
            assert( lengthOfLastWord("Hello World") == 5 );
        }

        void test2() {
            assert( lengthOfLastWord("   fly me   to   the moon  ") == 4 );
        }

        void test3() {
            assert( lengthOfLastWord("luffy is still joyboy") == 6 );
        }

        void test4() {
            assert( lengthOfLastWord("a") == 1 );
        }

        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();
            test3();
            test4();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
