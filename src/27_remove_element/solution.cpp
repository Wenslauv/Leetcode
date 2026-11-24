/**
 *
 * \file
 * \brief [Remove Element](https://leetcode.com/problems/remove-element/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.
 *
 * Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:
 *
 *  * Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
 *  * Return `k`.
 *
 *
 * <h4>Constrains</h4>
 *      `0 <= nums.length <= 100`
 *      `0 <= nums[i] <= 50`
 *      `0 <= val <= 100`
 */


#include <cassert>
#include <iostream>
#include <vector>

#include <doctest/doctest.h>


namespace leetcode::remove_element {

    int removeElement(std::vector<int>& nums, int val) {
        int size = static_cast<int>( nums.size() );
        
        int place = 0;

        for (int i = 0; i < size; ++i) {
            if (nums[i] != val) {
                nums[place] = nums[i];
                place ++;
            }
        }

        return place;
    }


    namespace testing {

        TEST_CASE("0027. Remove Element") {

            SUBCASE("test 1") {
                std::vector<int> nums {3,2,2,3};

                int k = removeElement( nums, 3 );

                CHECK( k == 2 );
                CHECK( nums[0] == 2);
                CHECK( nums[1] == 2);
            }


            SUBCASE("test 2") {
                std::vector<int> nums {0,1,2,2,3,0,4,2};

                int k = removeElement( nums, 2 );

                CHECK( k == 5 );
                CHECK( nums[0] == 0);
                CHECK( nums[1] == 1);
                CHECK( nums[2] == 3);
                CHECK( nums[3] == 0);
                CHECK( nums[4] == 4);
            }


            SUBCASE("test 3") {
                std::vector<int> nums {};

                int k = removeElement( nums, 0 );

                CHECK( k == 0 );
                CHECK( nums.empty() == true );
            }


            SUBCASE("test 4") {
                std::vector<int> nums { 1 };

                int k = removeElement( nums, 1 );

                CHECK( k == 0 );
            }


            SUBCASE("test 5") {
                std::vector<int> nums { 2 };

                int k = removeElement( nums, 3 );

                CHECK( k == 1 );
                CHECK( nums[0] == 2 );
            }

        }
    }   // namespace testing

}   // namespace leetcode::remove_element
