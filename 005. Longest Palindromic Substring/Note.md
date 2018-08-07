思路:
1. 遍历3次, 两次遍历确定所有子串, 对每个子串遍历一次检查是否是回文.
2. 动态规划, 建个table, table[i][j]==true 表示s[i,j]是回文, 这样要确定table[i][j]是否是回文只要看table[i+1][j-1]==1 && s[i]==s[j]就行. 时间复杂度$O(n^2)$, 空间复杂度$O(n^2)$
3. 时间复杂度$O(n^2)$, 空间复杂度$O(1)$, 按奇偶选取中心,从中心向两边寻找回文
4. [Manacher’s Algorithm – Linear Time Longest Palindromic Substring – Part 1](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/)

