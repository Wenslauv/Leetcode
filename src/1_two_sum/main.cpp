/**
 *
 * \file
 * \brief [Two Sum](https://leetcode.com/problems/two-sum/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * <h4>Constrains</h4>
 *      2 <= nums.length <= 104
 *      -10^9 <= nums[i] <= 10^9
 *      -10^9 <= target <= 10^9
 *      Only one valid answer exists.
 */


#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>


namespace leetcode {
    
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        const auto size = std::size(nums);

        std::unordered_map<int, int> cache {};

        for (int i = 0; i < size; ++i) {
            const int paired = target - nums[i];

            if (cache.count(paired)) {
                return { i, cache[paired] };
            }

            cache[ nums[i] ] = i;
        }

        return {};
    }



    namespace testing {

        void test1(void) {
            std::vector<int>    nums    { 2, 7, 11, 15};
            int                 target  { 9 };

            auto result = twoSum(nums, target);

            std::sort(result.begin(), result.end());
            assert(result[0] == 0);
            assert(result[1] == 1);
        }

        void test2() {
            std::vector<int>    nums    { 3, 2, 4};
            int                 target  { 6 };

            auto result = twoSum(nums, target);

            std::sort(result.begin(), result.end());
            assert(result[0] == 1);
            assert(result[1] == 2);
        }


        void test3() {
            std::vector<int>    nums    { 3, 3 };
            int                 target  { 6 };

            auto result = twoSum(nums, target);

            std::sort(result.begin(), result.end());
            assert(result[0] == 0);
            assert(result[1] == 1);
        }


        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();
            test3();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }

}



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
