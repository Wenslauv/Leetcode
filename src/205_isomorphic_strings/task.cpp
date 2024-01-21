/**
 *
 * \file
 * \brief [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given two strings `s` and `t`, determine if they are isomorphic.
 *
 * Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= s.length <= 5 * 10^4`
 *      `t.length == s.length`
 *      `s` and `t` consist of any valid ascii character.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>


namespace leetcode {

    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> subsTable {};

        int size = static_cast<int>( s.size() );

        for (int i = 0; i < size; ++i) {
            const char& symbol = s[i];

            if (subsTable.count( symbol) ) {
                const auto& sub = subsTable[symbol];

                if (t[i] != sub)
                    return false;

                t[i] = symbol;
            }
            else {
                const auto subSymbol = t[i];

                for (const auto& [key, value] : subsTable) {
                    if (value == subSymbol)
                        return false;
                }

                t[i] = symbol;

                subsTable[symbol] = subSymbol;
            }
        }

        return s == t;
    }


    namespace testing {

        void test1() {
            assert( isIsomorphic("egg", "add") == true );
        }

        void test2() {
            assert( isIsomorphic("foo", "bar") == false );
        }

        void test3() {
            assert( isIsomorphic("paper", "title") == true );
        }

        void test4() {
            assert( isIsomorphic("badc", "baba") == false );
        }

        void test5() {
            assert( isIsomorphic("egcd", "adfd") == false );
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
