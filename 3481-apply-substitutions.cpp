//https://leetcode.com/problems/apply-substitutions
class Solution {
public:
    string helper(string text, unordered_map<string, string> &m, unordered_set<string> &normal){
        string res = "";
        bool placeholder = false;
        for(auto ch: text){
            if(ch == '%'){
                placeholder = !placeholder;
                continue;
            }else if(ch == '_'){
                res += "_";
            }else if(placeholder){
                string key = "";
                key += ch;
                if(!normal.count(key)){
                    m[key] = helper(m[key], m, normal);
                    normal.insert(key);
                }
                res += m[key];
            }else{
                res += ch;
            }
        }
        return res;
    }
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> m;
        for(auto r: replacements){
            m[r[0]] = r[1];
        }
        unordered_set<string> normal;
        string res = helper(text, m, normal);
        return res;
    }
};

/*
[["E","vlcbqbf"],["Z","z%R%uda"],["R","%E%%E%"]]
"%R%_%Z%_%E%"
[["O","jha%R%"],["R","gzqvwg"]]
"%R%_%O%"
[["A","x"],["B","Y2"],["C","zz"],["D","k"]]
"%A%_%B%_%C%_%D%"

//need to modify these testcases
[["A","ab"],["B","%A%c"],["C","Z"],["D","%B%%C%"]]
"%D%%B%%A%%C%" 
[["A","p"],["B","%A%%A%"],["C","q7"],["D","%B%r"]]
"%B%%D%%C%%A%"
[["A","m1"],["B","%A%n"],["C","%B%"],["D","t"],["E","%D%%C%"]]
"%E%%B%%A%%D%%C%" 
[["A","a"],["B","%A%1"],["C","%B%2"],["D","%C%3"],["E","%D%4"],["F","%E%5"]]
"%F%%E%%D%%C%%B%%A%" 
[["A","X"],["B","%A%q"],["C","r%A%"],["D","%B%%C%"],["E","s"]]
"%D%%C%%B%%A%%E%"
[["A","aa"],["B","bb"],["C","%A%%B%"],["D","%C%z"],["E","Y"],["F","%E%%D%"]]
"%F%%D%%C%%B%%A%%E%"
[["A","h"],["B","%A%"],["C","%B%%A%"],["D","w"],["E","%D%%C%"],["F","9"],["G","%F%%E%"]]
"%G%%E%%C%%B%%A%%D%%F%"
[["A","1"],["B","%A%2"],["C","%B%3"],["D","%C%4"],["E","%D%5"],["F","%E%6"],["G","%F%7"],["H","%G%8"]]
"%H%%G%%F%%E%%D%%C%%B%%A%"
[["A","q"],["B","w"],["C","e"],["D","%A%%B%%C%"],["E","%D%r"],["F","t"],["G","%F%%E%"],["H","y"],["I","%G%%H%"],["J","u"]]
"%J%%I%%H%%G%%F%%E%%D%%C%%B%_%A%"
*/
