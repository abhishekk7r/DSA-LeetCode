class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> nei;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) return 0;
        wordList.push_back(beginWord);
        for(auto word:wordList){
            for(int i=0; i<word.size(); i++){
                string pattern = word;
                pattern[i] = '*';
                nei[pattern].push_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                string word = q.front();
                q.pop();


                if(word == endWord) return res;

                for(int j=0; j<word.size(); j++){
                    string pattern = word;
                    pattern[j] = '*';

                    for(string& neiWord : nei[pattern]){
                        if(visited.find(neiWord) == visited.end()){
                            visited.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};