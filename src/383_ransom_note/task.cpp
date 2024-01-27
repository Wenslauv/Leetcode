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


namespace leetcode {

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

        void test1() {
            assert( canConstruct( "a", "b") == false);
        }

        void test2() {
            assert( canConstruct( "aa", "ab") == false);

        }

        void test3() {
            assert( canConstruct( "aa", "aab") == true);
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
