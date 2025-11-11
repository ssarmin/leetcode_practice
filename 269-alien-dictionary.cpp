//https://neetcode.io/problems/foreign-dictionary
class Solution {
public:
    void update(unordered_map<char, unordered_set<char>> &m, string str1, string str2){
        int len = min((int)str1.size(), (int)str2.size());
        for(int i=0; i<len; i++){
            if(str1[i] != str2[i]){
                m[str1[i]].insert(str2[i]);
                return;
            }
        }
        if(str1.size() > str2.size())
            m.clear();
    }
    string bfs(unordered_map<char, int> &m_indegree, unordered_map<char, unordered_set<char>> &m){
        queue<char> q;
        for(auto a: m_indegree){
            if(a.second == 0)
                q.push(a.first);
        }
        string res = "";
        while(!q.empty()){
            char ch = q.front();
            q.pop();
            res += ch;
            for(auto next: m[ch]){
                m_indegree[next]--;
                if(m_indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        if(res.size() != m_indegree.size())
            return "";
        return res;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> m;
        for(auto word: words){
            for(auto ch: word){
                m[ch];   
            }
        }
        for(int i=0; i<words.size()-1; i++){
            update(m, words[i], words[i+1]);
            if(m.empty())
                return "";
        }
        
        unordered_map<char, int> m_indegree;
        for(auto a: m){
            if(!m_indegree.count(a.first))
                m_indegree[a.first] = 0;
            for(auto next: a.second){
                m_indegree[next]++;
            }
        }
        return bfs(m_indegree, m);
    }
};
