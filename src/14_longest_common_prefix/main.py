#!usr/bin/python

#
# \file
# \brief [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
#
# \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
#
# \details
# <h4>Problem</h4>
# Write a function to find the longest common prefix string amongst an array of strings.
#
# If there is no common prefix, return an empty string "".
#
#
# <h4>Constrains</h4>
#       1 <= strs.length <= 200
#       0 <= strs[i].length <= 200
#       strs[i] consists of only lowercase English letters.
#


from typing import List


def longestCommonPrefix(strs: List[str]) -> str:
    strs.sort()
    first, last = strs[0], strs[ -1 ]

    commonLength = min( len(first), len(last) )

    prefix = "";
    for i in range( commonLength ):
        if (first[i] == last[i]):
            prefix += first[i]
        else:
            return prefix

    return prefix

    
class Testcase:
    def test1():
        assert longestCommonPrefix( ["flower","flow","flight"] ) == "fl"


    def test2():
         assert longestCommonPrefix( ["dog","racecar","car"] ) == ""

    
    def test3():
         assert longestCommonPrefix( ["ab","a"] ) == "a"


    
    def runTests():
        print("Running predefined tests...")

        Testcase.test1()
        Testcase.test2()
        Testcase.test3()

        print("All tests passed successfully")





if __name__ == "__main__":
    Testcase.runTests()
    