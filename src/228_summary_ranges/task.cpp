/**
 *
 * \file
 * \brief [Summary Ranges](https://leetcode.com/problems/summary-ranges/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * You are given a sorted unique integer array `nums`.
 *
 * A range `[a,b]` is the set of all integers from `a` to `b` (inclusive).
 *
 * Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.
 *
 * Each range `[a,b]` in the list should be output as:
 *  `"a->b"` if `a != b`
 *  `"a"` if `a == b`
 *
 *
 * <h4>Constrains</h4>
 *      `0 <= nums.length <= 20`
 *      `-231 <= nums[i] <= 231 - 1`
 *      All the values of `nums` are unique.
 *      `nums` is sorted in ascending order.
 */


#include <cassert>
#include <iostream>
#include <string>
#include <vector>


namespace leetcode {

    std::string intervalToString(const int& start, const int& end) {
        if (start == end) {
            return std::to_string(start);
        }

        return std::to_string(start) + "->" + std::to_string(end);
    }


    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        const int size = static_cast<int>( std::size(nums) );

        if (size == 0)
            return {};

        std::vector<std::string> ranges {};

        int startInterval   { nums.front() };
        int endInterval     { nums.front() };

        bool skipFirst = true;

        for (const int& value : nums) {
            if (skipFirst) {
                skipFirst = false;
                continue;
            }

            if ((endInterval + 1) == value) {
                endInterval = value;
            }
            else {
                ranges.push_back( intervalToString(startInterval, endInterval) );

                startInterval = endInterval = value;
            }

        }

        ranges.push_back( intervalToString( startInterval, endInterval) );

        return ranges;
    }


    namespace testing {

        void test1() {
            std::vector<int> nums {0,1,2,4,5,7};
            
            assert( summaryRanges( nums ) == (std::vector<std::string>{ "0->2", "4->5", "7" }) );
        }

        void test2() {
            std::vector<int> nums {0,2,3,4,6,8,9};

            assert( summaryRanges( nums ) == (std::vector<std::string>{ "0","2->4","6","8->9" }) );
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
