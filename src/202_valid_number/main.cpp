/**
 *
 * \file
 * \brief [Happy Number](https://leetcode.com/problems/happy-number/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Write an algorithm to determine if a number n is happy.
 * 
 * A happy number is a number defined by the following process:
 *  * Starting with any positive integer, replace the number by the sum of the squares of its digits.
 *  * Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 *  * Those numbers for which this process ends in 1 are happy.
 *
 * Return true if n is a happy number, and false if not.
 *
 *
 * <h4>Constrains</h4>
 *      1 <= n <= 2^31 - 1
 *      s and t consist of lowercase English letters.
 */


#include <cassert>
#include <iostream>
#include <unordered_set>


namespace leetcode {

    int squareDigits(int n) {
        int sum{};

        while (n > 0) {
            int digit = n % 10;
            sum += (digit * digit);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> prev {};

        while (n != 1) {
            prev.insert(n);

            n = squareDigits(n);

            if (prev.count(n))
                return false;
        }

        return true;
    }


    namespace testing {

        void test1(void) {
            assert( isHappy(19) == true );
        }

        void test2() {
            assert( isHappy(2) == false );

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
