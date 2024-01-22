/**
 *
 * \file
 * \brief [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
 *
 * An input string is valid if:
 *  * Open brackets must be closed by the same type of brackets.
 *  * Open brackets must be closed in the correct order.
 *  * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= s.length <= 10^4`
 *      `s` consists of parentheses only `()[]{}`.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <vector>


namespace leetcode {

    bool isValid(std::string s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        std::vector<char> order {};
        order.reserve( s.length() );

        for (const char& c : s) {

            if (c == '(' or c == '{' or c == '[') {
                order.push_back( c );
            }
            else {
                if (order.empty())
                    return false;

                auto last = order.back();
                order.pop_back();

                if (c == ')' and last != '(')   return false;
                if (c == '}' and last != '{')   return false;
                if (c == ']' and last != '[')   return false;
            }
        }

        return order.empty();
    }


    namespace testing {

        void test1() {
            assert( isValid( "()" ) == true );
        }

        void test2() {
            assert( isValid( "()[]{}" ) == true );
        }

        void test3() {
            assert( isValid( "(]" ) == false );
        }

        void test4() {
            assert( isValid( "([)]" ) == false );
        }

        void test5() {
            assert( isValid( "){" ) == false );
        }

        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();
            test3();
            test4();
            test5();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
