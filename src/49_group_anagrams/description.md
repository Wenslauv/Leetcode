# Group Anagrams


### Links
[Leetcode task page](https://leetcode.com/problems/group-anagrams/)


### Problem
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it [in-place](https://en.wikipedia.org/wiki/In-place_algorithm).

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



### Examples
 
##### Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


##### Example 2:

Input: strs = [""]

Output: [[""]]


##### Example 3:

Input: strs = ["a"]

Output: [["a"]]



### Constraints
- `1 <= strs.length <= 104`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.




### Solution

To solve this with O(1) space, we use first row and first column values as a flags that indicate this row/column has zero anywhere in it or not.
So:
1. Memorize if first row has zeroes in it (we need to keep this info, because some of row's values will be changed to zero lately).
2. Memorize if first column has zeroes for the same reasons.
3. Iterate over entire matrix to find zero cells and set their first column/row elements to zero.
4. Iterate over entire matrix again to change cell value to zero ONLY IF their first column/first row value is zero.
5. If first row had zeroes, set all first row to zeroes.
6. The same should be made also for first column.