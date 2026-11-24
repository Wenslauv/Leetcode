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
#include <algorithm>
#include <cassert>
#include <iostream>

#include <doctest/doctest.h>



namespace leetcode::two_sum {
    
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        const auto size = std::ssize(nums);

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

        TEST_CASE("0001. Two Sum") {

            SUBCASE("test 1") {
                std::vector<int>    nums    { 2, 7, 11, 15};
                int                 target  { 9 };

                auto result = twoSum(nums, target);

                std::sort(result.begin(), result.end());
                CHECK(result[0] == 0);
                CHECK(result[1] == 1);
            }


            SUBCASE("test 2") {
                std::vector<int>    nums    { 3, 2, 4};
                int                 target  { 6 };

                auto result = twoSum(nums, target);

                std::sort(result.begin(), result.end());
                CHECK(result[0] == 1);
                CHECK(result[1] == 2);
            }


            SUBCASE("test 3") {
                std::vector<int>    nums    { 3, 3 };
                int                 target  { 6 };

                auto result = twoSum(nums, target);

                std::sort(result.begin(), result.end());
                CHECK(result[0] == 0);
                CHECK(result[1] == 1);
            }

        }
    }

}