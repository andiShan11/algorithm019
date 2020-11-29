class Solution {
private:
    unordered_map<string, int> wordId;
    // vector<string> idWord;
    vector<vector<int>> edges;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string& word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
            }
        }
        if (!wordId.count(endWord)) {
            return 0;
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            wordList.push_back(beginWord);
        }

        edges.resize(wordList.size());
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (transformCheck(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int dest = wordId[endWord];
        queue<int>q;
        vector<int>cost(id, INT_MAX);
        q.push(wordId[beginWord]);
        cost[wordId[beginWord]]=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=0;i<edges[now].size();i++){
                int to=edges[now][i];
                if(cost[now]+1<cost[to]){
                    cost[to]=cost[now]+1;
                    q.push(to);
                }
            }
        }
        return cost[dest]==INT_MAX?0:cost[dest];
    }
     bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};
