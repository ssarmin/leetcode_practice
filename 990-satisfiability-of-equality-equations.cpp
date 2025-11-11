//https://leetcode.com/problems/satisfiability-of-equality-equations
class Solution {
public:
    bool check(char ch1, char ch2, unordered_map<char, unordered_set<char>> m){
        queue<char> q;
        q.push(ch1);
        unordered_set<char> visit;
        while(!q.empty()){
            ch1 = q.front();
            if(ch1 == ch2)
                return true;
            q.pop();
            if(visit.count(ch1) || !m.count(ch1))
                continue;
            visit.insert(ch1);
            for(auto a: m[ch1]){
                if(ch2 == a)
                    return false;
                if(!visit.count(a)){
                    q.push(a);
                }
            }
        }
        return true;
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, unordered_set<char>> m;
        vector<int> neg;
        for(int i=0; i<equations.size(); i++){
            if(equations[i][1] == '!'){
                if(equations[i][0] == equations[i][3])
                    return false;
                neg.push_back(i);
            }else{
                m[equations[i][0]].insert(equations[i][3]);
                m[equations[i][3]].insert(equations[i][0]);
            }
        }
        for(auto i: neg){
            if(!check(equations[i][0], equations[i][3], m))
                return false;
        }
        return true;
    }
};

["c==c","f!=a","f==b","b==c"]
["e==d","e==a","f!=d","b!=c","a==b"]
["a==b", "b==c", "c!=d", "e==a", "p==q", "q==r"]
["a==b","b!=a"]
["b==a","a==b"]
["d!=f","f==e","a==b","a==c"]
["a==b","b==c","a==c"]
["a==b","b!=c","c==a"]
["c==c","f!=a","f==b","b==c"]
["e==e","d!=e","c==d","d!=e"]
["b==a","a==b"]
["d!=f","f==e","a==b","a==c"]
["a==b","b==c","a==c"]
["a!=a"]
