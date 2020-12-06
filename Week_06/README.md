* [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)

非常常规的动态规划题

* [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)

优点类似走楼梯问题，**<u>是一个有限制的走楼梯问题</u>**。

* [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

和最小路径和优点相似

* [647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)

可以用动态规划来解决，`dp[i][j]` 表示子串 `s[i:j]` 是否是回文串，时间和空间复杂度均为 $O(n^2)$。

另外，还可以用 `Manacher` 来解决。

* [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)

`dp[i]` 表示以字符 `s[i]` 作为结尾的最长有效括号。
$$
dp[i]=
\begin{cases}
dp[i-2]+2& \text{s[i]=='('&&s[i-1]==')'}\\
dp[i-1]+(i>=2+dp[i-1]?dp[i-2-dp[i-1]]:0)+2& \text{s[i]=='('&&s[i-1]!=')'&&s[i-dp[i-1]-1] == '('}
\end{cases}
$$

* [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)

非常常规的动态规划

* [410. 分割最大值](https://leetcode-cn.com/problems/split-array-largest-sum/) 

二分法

* [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)

滑动窗口

* [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)

递归法。正向考虑时，如果戳破一个气球，整个数组会汇合到一起，无法划分成子问题，所以反向考虑，第一个戳破的气球考虑成最后一个戳破。







