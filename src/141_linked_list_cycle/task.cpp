/**
 *
 * \file
 * \brief [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 *
 * \details
 * <h4>Problem</h4>
 * Given `head`, the head of a linked list, determine if the linked list has a cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
 * following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer
 * is connected to. Note that `pos` is not passed as a parameter.
 *
 * Return `true` if there is a cycle in the linked list. Otherwise, return `false`.
 *
 *
 * <h4>Constrains</h4>
 *      `1 <= ransomNote.length, magazine.length <= 10^5`
 *      `ransomNote` and `magazine` consist of lowercase English letters.
 *      The number of the nodes in the list is in the range `[0, 10^4]`.
 *      `-10^5 <= Node.val <= 10^5`
 *      `pos` is `-1` or a valid index in the linked-list.
 */


#include <cassert>
#include <iostream>
#include <string>


namespace leetcode {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };


    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }



    namespace testing {

        void test1() {
            std::vector<ListNode> nodes = {
                ListNode(3),
                ListNode(2),
                ListNode(0),
                ListNode(-4)
            };

            nodes[0].next = &nodes[1];
            nodes[1].next = &nodes[2];
            nodes[2].next = &nodes[3];
            nodes[3].next = &nodes[1];

            assert( hasCycle( &nodes[0] ) == true);
        }

        void test2() {
            std::vector<ListNode> nodes = {
                ListNode(1),
                ListNode(2),
            };

            nodes[0].next = &nodes[1];
            nodes[1].next = &nodes[0];

            assert( hasCycle( &nodes[0] ) == true);
        }

        void test3() {
            std::vector<ListNode> nodes = {
                ListNode(1),
            };

            assert( hasCycle( &nodes[0] ) == false);        }


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
