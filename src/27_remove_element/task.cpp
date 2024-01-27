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


namespace leetcode {

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

        void test1() {
            std::vector<int> nums {3,2,2,3};

            int k = removeElement( nums, 3 );

            assert( k == 2 );
            assert( nums[0] == 2);
            assert( nums[1] == 2);
        }

        void test2() {
            std::vector<int> nums {0,1,2,2,3,0,4,2};

            int k = removeElement( nums, 2 );

            assert( k == 5 );
            assert( nums[0] == 0);
            assert( nums[1] == 1);
            assert( nums[2] == 3);
            assert( nums[3] == 0);
            assert( nums[4] == 4);
        }

        void test3() {
            std::vector<int> nums {};

            int k = removeElement( nums, 0 );

            assert( k == 0 );
            assert( nums.empty() == true );
        }

        void test4() {
            std::vector<int> nums { 1 };

            int k = removeElement( nums, 1 );

            assert( k == 0 );
        }

        void test5() {
            std::vector<int> nums { 2 };

            int k = removeElement( nums, 3 );

            assert( k == 1 );
            assert( nums[0] == 2 );

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
