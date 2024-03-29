/**
 *
 * \file
 * \brief [Roman To Integert](https://leetcode.com/problems/roman-to-integer/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol       Value
 * I                    1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 *  I can be placed before V (5) and X (10) to make 4 and 9.
 *  X can be placed before L (50) and C (100) to make 40 and 90.
 *  C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 * Given a roman numeral, convert it to an integer.
 *
 * <h4>Constrains</h4>
 *      1 <= s.length <= 15
 *      s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 *      It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */


#include <vector>
#include <cassert>
#include <iostream>


namespace leetcode {
    
    int convert(char c) {
                if (c == 'I')  return 1;
        else    if (c == 'V')  return 5;
        else    if (c == 'X')  return 10;
        else    if (c == 'L')  return 50;
        else    if (c == 'C')  return 100;
        else    if (c == 'D')  return 500;
        else    if (c == 'M')  return 1000;

        return 0;
    }


    int romanToInt(std::string s) {
        int sum {};

        for (int i = static_cast<int>(s.length() - 1); i >= 0; --i) {
            if (i != 0) {
                int s_curr = convert( s[i] );
                int s_prev = convert( s[i-1] );

                if (s_curr > s_prev) {
                    sum += (s_curr - s_prev);
                    --i;
                }
                else {
                    sum += s_curr;
                }
            }
            else {
                sum += convert( s[i] );
            }
        }

        return sum;
    }



    namespace testing {

        void test1(void) {
            assert( romanToInt("III") == 3 );
        }

        void test2() {
            assert( romanToInt("LVIII") == 58 );
        }

        void test3() {
            assert( romanToInt("MCMXCIV") == 1994 );
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
