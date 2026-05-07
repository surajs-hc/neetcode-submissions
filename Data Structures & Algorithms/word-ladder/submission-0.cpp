class Solution {
private:
    bool related(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return true;
    }
    void buildGraph(vector<vector<int>>& adjList, const vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); ++i) {
            for (int k = i + 1; k < wordList.size(); ++k) {
                if (related(wordList[i], wordList[k])) {
                    adjList[i].push_back(k);
                    adjList[k].push_back(i);
                }
            }
        }
    }
    int shortestPath(vector<vector<int>>& adjList, int begin, int end) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;
        q.push(begin);
        visited[begin] = true;

        int pathLength = 1;
        while (!q.empty()) {
            int numNodes = q.size();
            for (int count = 0; count < numNodes; ++count) {
                int node = q.front();
                q.pop();

                if (node == end) {
                    return pathLength;
                }
                for (int edgeNode : adjList[node]) {
                    if (!visited[edgeNode]) {
                        visited[edgeNode] = true;
                        q.push(edgeNode);
                    }
                }
            }
            ++pathLength;
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return 0;
        }
        int beginNode = -1;
        int endNode = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) {
                beginNode = i;
            }
            else if (wordList[i] == endWord) {
                endNode = i;
            }
        }
        if (endNode == -1) {
            return 0;
        }
        if (beginNode == -1) {
            wordList.push_back(beginWord);
            beginNode = wordList.size() - 1;
        }


        vector<vector<int>> adjList(wordList.size());
        unordered_map<string, int> wordIndex;
        buildGraph(adjList, wordList);
        return shortestPath(adjList, beginNode, endNode);
    }
};
