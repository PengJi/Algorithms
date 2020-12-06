class Trie {
private:
    struct Node {
        unordered_map<int, Node*> next;
        bool isContain;
        Node() {
            unordered_map<int, Node*> nextt;
            next = nextt;
            isContain = false;
        }
    };

    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        auto temp = root;
        insert(word, temp);
    }

    void insert(string word, Node* currentNode) {
        if (word[0] == '\0') {
            currentNode->isContain = true;
            return;
        }
        int key = word[0] - 97;
        Node* next = currentNode->next[key];
        if (next == NULL) {
            auto newNode = new Node();
            currentNode->next[key] = newNode;
            insert(&word[1], currentNode->next[key]);
        }
        else {
            insert(&word[1], currentNode->next[key]);
        }
    }

    bool isContain(string word) {
        auto temp = root;
       return isContain(word, temp);

    }

    bool isContain(string word, Node* currentNode) {
        if (word[0] == '\0') {
            return currentNode->isContain;
        }
        int key = word[0] - 97;
        auto next = currentNode->next[key];
        if (next == NULL) {
            return false;
        }
        else {
            return isContain(&word[1], next);
        }
    }

    bool isContainWith(string word) {
        auto temp = root;
        return isContainWith(word,temp);
    }


    bool isContainWith(string word, Node* currentNode) {
        if (word == "eat") {
            int i = 0;
        }
        if (word[0] == '\0') {
            return true;
        }
        int key = word[0] - 97;
        auto next = currentNode->next[key];
        if (next == NULL) {
            return false;
        }
        else {
            auto r= isContainWith(&word[1], currentNode->next[key]);
            return r;
        }
        
    }
};

class Solution {
public:
    int maxLength = 0;
    pair<int, int> dir[4] = {   {0,-1}, {0,1},{-1,0},{1,0 } };
    Trie* Tr;
    vector<string> ans;
    int wordNum;
    bool isAllFind = false;
    unordered_map<string, bool> myMap ;
    unordered_map<string, bool> myMap2;

    // https://leetcode-cn.com/problems/word-search-ii/solution/c-shuang-yi-bai-zi-dian-shu-jia-hui-su-ji-lu-yi-xi/
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Tr = new Trie();
        for (int i = 0;i < words.size();i++) {
            Tr->insert(words[i]);
            wordNum = i;
        }

        int x = board[0].size();
        int y = board.size();
        for (int i = 0;i < y;i++) {
            if (isAllFind) {
                break;
            }
            for (int j = 0;j < x;j++) {
                if (isAllFind) {
                    break;
                }
                string rt = "";
                pair<int, int> currentPoint = { j,i };
                Check(board, rt, currentPoint);
            }
        }
        return ans;  
    }

    void Check(vector<vector<char>>& board, string& rt, pair<int, int> currPoint) {
        int x = currPoint.first;
        int y = currPoint.second;
        if (x >= board[0].size() || x < 0 || y >= board.size() || y < 0) {
            return;
        }
        char c = board[y][x];
        rt.push_back(c);
        if (myMap2.find(rt) != myMap2.end()) {
            return;
        }
        auto key = PairToStr(currPoint);
        myMap[key] = true;
        bool isContainWith= Tr->isContainWith(rt);
        if (isContainWith) {
            bool isContain = Tr->isContain(rt);
            if (isContain) {
             
                    ans.push_back(rt);
                    myMap2[rt] = true;
                    if (ans.size() == wordNum + 1) {
                        isAllFind = true;
                        return;
                    }

            }
            for (int i = 0;i < 4;i++) {
                if (isAllFind) {
                    break;
                }
                int nextx = dir[i].first + x;
                int nexty = dir[i].second + y;
                pair<int, int> nextPoint = { nextx,nexty };
                string nextPointKey = PairToStr(nextPoint);
                if (myMap.find(nextPointKey) == myMap.end()) {
                    Check(board, rt, nextPoint);
                }
                else if (!myMap[nextPointKey]) {
                    Check(board, rt, nextPoint);
                }
            }
        }
        else {
            rt.pop_back();
            myMap[key] = false;
            return;
        }
        rt.pop_back();
        myMap[key] = false;
    };

    string PairToStr(pair<int, int> p) {
        return to_string(p.first) + to_string(p.second);
    }
};
