/**
 *
 * \file
 * \brief [Palindrome Number](https://leetcode.com/problems/palindrome-number/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * <h4>Constrains</h4>
 *      -231 <= x <= 231 - 1
 */


#include <vector>
#include <cassert>
#include <iostream>


namespace leetcode {
    
    bool isPalindrome(int x) {
            if (x < 0)
                return false;

            long int reversed = 0;
            long int origin = x;

            while (x != 0) {
                reversed = reversed * 10 + x % 10;
                x /= 10;
            }

            return (reversed == origin);
        }



    namespace testing {

        void test1(void) {
            assert( isPalindrome(121) == true );
        }

        void test2() {
            assert( isPalindrome(-121) == false );
        }

        void test3() {
            assert( isPalindrome(10) == false );
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
