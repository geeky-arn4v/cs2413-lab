#include <stddef.h>

/*
Question 1: Longest Common Prefix

Write a function to find the longest common prefix string
among an array of strings.

A prefix is the beginning part of a string.

Examples:
Input: ["flower", "flow", "flight"]
Output: "fl"

Input: ["dog", "racecar", "car"]
Output: ""

IMPORTANT:
- You ARE allowed to modify the first string (strs[0])
- You should store the result directly in strs[0]
- Return strs[0] as the result
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    static char empty[] = "";
    if (strsSize <= 0 || strs == NULL) {
        return empty;
    }
    int len = 0;
    while (strs[0][len] != '\0') {
        char c = strs[0][len];
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][len] != c || strs[i][len] == '\0') {
                strs[0][len] = '\0';
                return strs[0];
            }
        }
        len++;
    }
    return strs[0];
}
