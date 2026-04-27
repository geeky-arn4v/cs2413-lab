#include <stddef.h>
#include <stdbool.h>

/*
Question 3: Is Subsequence

Given two strings s and t, return true if s is a subsequence of t,
or false otherwise.

A subsequence of a string is a new string formed from the original
string by deleting some characters without changing the order of
the remaining characters.

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Hint:
- This can be solved using two pointers.
*/

bool isSubsequence(char* s, char* t) {
    if (s == NULL || t == NULL) {
        return false;
    }
    if (s[0] == '\0') {
        return true;
    }
    int i = 0;
    for (; t[0] != '\0'; t++) {
        if (t[0] == s[i]) {
            i++;
            if (s[i] == '\0') {
                return true;
            }
        }
    }
    return false;
}
