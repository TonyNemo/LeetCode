Solution
======

Approach1:Brute Force
---
Nested loop

**complexity analysis** 
* time complexity: $O(n^2)$
* space complexity: $O(1)$


Approach2:Hash
-----
Use a hash table to map element to index. Iterate twice. First constuct a hash map, then check the fit index.

**complexity analysis** 
* time complexity: $O(n)$
* space complexity: $O(n)$

Approach3:Hash w/ one iteration
-----
insert and check in one iteration.