/**
 *
 * \file
 * \brief [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii//)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given an integer array `nums` sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice.
 * The relative order of the elements should be kept the same.
 *
 * Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array `nums`.
 * More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.
 *
 * Return `k` after placing the final result in the first `k` slots of `nums`.
 *
 * Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= nums.length <= 3 * 10^4`
 *      `-10^4 <= nums[i] <= 10^4`
 *      `nums` is sorted in non-decreasing order.
 */


#include <cassert>
#include <iostream>
#include <vector>


namespace leetcode {

    int removeDuplicates(std::vector<int>& nums) {
        int unique = nums[0];
        int count  = 1;
        int index = 1;

        int size    = static_cast<int>( std::size(nums) );

        for (int i = 1; i < size; ++i ) {
            if (nums[i] == unique) {
                if (count < 2) {
                    count ++;
                    nums[index] = nums[i];
                    index ++;
                }
            }
            else {
                nums[index] = nums[i];
                unique = nums[i];
                index ++;
                count = 1;
            }
        }

        return index;
    }


    namespace testing {

        void test1(void) {
            std::vector<int> nums       {1,1,1,2,2,3};
            std::vector<int> expected   {1,1,2,2,3};

            int k = removeDuplicates(nums);
            assert(k == expected.size());
            for (int i = 0; i < k; i++) {
                assert(nums[i] == expected[i]);
            }
        }

        void test2() {
            std::vector<int> nums       {0,0,1,1,1,1,2,3,3};
            std::vector<int> expected   {0,0,1,1,2,3,3};

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
