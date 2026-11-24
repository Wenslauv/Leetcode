/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include <doctest/doctest.h>


namespace leetcode::evaluate_reverse_polish_notation {

    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> prn {};

        for (const auto& token : tokens) {
            if (token == "+" or token == "-" or token == "*" or token == "/") {
                int first_operand = prn.top();
                prn.pop();

                int second_operand = prn.top();
                prn.pop();

                if      (token == "+")   prn.push( second_operand + first_operand );
                else if (token == "-")   prn.push( second_operand - first_operand );
                else if (token == "*")   prn.push( second_operand * first_operand );
                else if (token == "/")   prn.push( second_operand / first_operand );
            }
            else {
                prn.push( std::stoi(token) );
            }
        }

        return prn.top();
    }


    namespace testing {

        TEST_CASE("0150. Evaluate Reverse Polish Notation") {

            SUBCASE("test 1") {
                std::vector<std::string> tokens {"2","1","+","3","*"};
                int expected = 9;

                auto result = evalRPN(tokens);
                CHECK(result == expected);
            }


            SUBCASE("test 2") {
                std::vector<std::string> tokens {"4","13","5","/","+"};
                int expected = 6;

                auto result = evalRPN(tokens);
                CHECK(result == expected);
            }


            SUBCASE("test 3") {
                std::vector<std::string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
                int expected = 22;

                auto result = evalRPN(tokens);
                CHECK(result == expected);
            }

        }
    }   // namespace testing

}   // namespace leetcode::evaluate_reverse_polish_notation
