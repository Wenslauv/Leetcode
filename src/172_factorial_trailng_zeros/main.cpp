/**
 *
 * \file
 * \brief [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
 *
 *
 * <h4>Constrains</h4>
 *      0 <= n <= 10^4
 */


#include <cassert>
#include <iostream>


namespace leetcode {

    int trailingZeroes(int n) {
        int count {};

        while (n / 5 > 0) {
            count += n / 5;
            n /= 5;
        }

        return count;
    }


    namespace testing {

        void test1(void) {
            assert( trailingZeroes(3) == 0 );
        }

        void test2() {
            assert( trailingZeroes(5) == 1 );
        }

        void test3() {
            assert( trailingZeroes(0) == 0 );
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
