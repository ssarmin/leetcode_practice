//https://leetcode.com/problems/kill-process
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m_child;
        for(int i=0; i<pid.size(); i++){
            m_child[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto n: m_child[node]){
                q.push(n);
            }
        }
        return res;
    }
};
