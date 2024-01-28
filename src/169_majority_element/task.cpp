/**
 *
 * \file
 * \brief [Majority Element](https://leetcode.com/problems/majority-element/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an array `nums` of size `n`, return the majority element.
 *
 * The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.
 *
 *
 * <h4>Constrains</h4>
 *      `n == nums.length`
 *      `1 <= n <= 5 * 10^4`
 *      `-10^9 <= nums[i] <= 10^9`
 */


#include <cassert>
#include <iostream>
#include <vector>


namespace leetcode {

    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        int size = static_cast<int>( std::size(nums) );


        for (int i = 0; i < size; ++i) {
            if (count == 0) {
                candidate = nums[i];
                count ++;
            }
            else {
                if  (candidate == nums[i])  count ++;
                else                        count --;
            }
        }

        return candidate;
    }



    namespace testing {

        void test1() {
            std::vector<int> nums { 3,2,3 };

            assert( majorityElement(nums) == 3);
        }

        void test2() {
            std::vector<int> nums { 2,2,1,1,1,2,2 };

            assert( majorityElement(nums) == 2);
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
