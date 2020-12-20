class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
    queue<string> q{{start}};
    unordered_set<string> seen{start};
    unordered_set<string> b(bank.begin(), bank.end());
    
    int steps = 0;
    while (not q.empty()) {
      size_t size = q.size();
      while (size--) {
        const auto& cur = q.front(); q.pop();
        if (cur == end) return steps;
        for (int i = 0; i < 8; ++i) {
          string nxt(cur);
          for (const auto& c : {'A', 'C', 'G', 'T'}) {
            if (cur[i] != c) nxt[i] = c;
            if (!b.count(nxt) || !seen.emplace(nxt).second)
              continue;
            q.emplace(nxt);
          }
        }
      }
      ++steps;
    }
    return -1;
  }
};
