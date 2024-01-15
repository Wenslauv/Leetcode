/**
 *
 * \file
 * \brief [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. 
 * Then return the number of unique elements in nums.
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 *
 *
 * <h4>Constrains</h4>
 *      1 <= nums.length <= 3 * 10^4
 *      -100 <= nums[i] <= 100
 *      nums is sorted in non-decreasing order.
 */


#include <cassert>
#include <iostream>
#include <vector>


namespace leetcode {

    int removeDuplicates(std::vector<int>& nums) {
        int unique  = 1;
        int size    = static_cast<int>( std::size(nums) );

        for (int i = 1; i < size; ++i ) {
            if (nums[i] != nums[i-1]) {
                nums[unique] = nums[i];
                unique++;

            }
        }

        return unique;
    }


    namespace testing {

        void test1(void) {
            std::vector<int> nums       {1, 1, 2};
            std::vector<int> expected   {1, 2};

            int k = removeDuplicates(nums);
            assert(k == expected.size());
            for (int i = 0; i < k; i++) {
                assert(nums[i] == expected[i]);
            }
        }

        void test2() {
            std::vector<int> nums       {0,0,1,1,1,2,2,3,3,4};
            std::vector<int> expected   {0,1,2,3,4};

            int k = removeDuplicates(nums);
            assert(k == expected.size());
            for (int i = 0; i < k; i++) {
                assert(nums[i] == expected[i]);
            }
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
