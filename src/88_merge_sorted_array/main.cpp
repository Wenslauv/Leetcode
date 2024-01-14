/**
 *
 * \file
 * \brief [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 *
 * <h4>Constrains</h4>
 *      nums1.length == m + n
 *      nums2.length == n
 *      0 <= m, n <= 200
 *      1 <= m + n <= 200
 *      -10^9 <= nums1[i], nums2[j] <= 10^9
 */


#include <vector>
#include <cassert>
#include <iostream>


namespace leetcode {
    
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        /* 
         Let 
         idxA is the number of the last effective num1 index,
         idxB is the number of the last effective num2 index,
         and idxR is the last result index.
        */

        int idxA = m - 1;
        int idxB = n - 1;
        int idxR = static_cast<int>(std::size(nums1)) - 1;

        while (idxR >= 1) {
            
            if (idxA >= 0 and idxB >= 0) {
                int& valueA = nums1[idxA];
                int& valueB = nums2[idxB];

                if (valueB >= valueA) {
                    std::swap( nums1[ idxR ], valueB );
                    idxB -- ;
                }
                else {
                    std::swap( nums1[ idxR ], valueA );
                    idxA --;
                }
            }
            else if (idxA >= 0 and idxB < 0) {
                int& value1 = nums1[idxA];
                std::swap( nums1[ idxR ], value1 );
                idxA --;
            }
            else if (idxB >= 0 and idxA < 0) {
                int& value2 = nums2[idxB];
                std::swap( nums1[ idxR ], value2 );
                idxB --;
            }

            idxR --;
        }
    }



    namespace testing {

        void test1(void) {
            std::vector<int>    nums1   { 1,2,3,0,0,0 };
            int                 m       { 3 };

            std::vector<int>    nums2   { 2,5,6 };
            int                 n       { 3 };

            merge(nums1, m, nums2, n);
            
            assert( (nums1 == std::vector{ 1,2,2,3,5,6 }) );
        }

        void test2() {
            std::vector<int>    nums1   { 1 };
            int                 m       { 1 };

            std::vector<int>    nums2   { };
            int                 n       { 0 };

            merge(nums1, m, nums2, n);

            assert( (nums1 == std::vector{ 1 }) );
        }


        void test3() {
            std::vector<int>    nums1   { 0 };
            int                 m       { 0 };

            std::vector<int>    nums2   { 1 };
            int                 n       { 1 };

            merge(nums1, m, nums2, n);

            assert( (nums1 == std::vector{ 1 }) );
        }


        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();
            test3();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
