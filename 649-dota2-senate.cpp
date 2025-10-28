//https://leetcode.com/problems/dota2-senate
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        for(auto ch: senate){
            q.push(ch);
        }
        int d = 0;
        int r = 0;
        while(q.size() > 1){
            int size = q.size();
            for(int s=0; s<size; s++){
                char ch = q.front();
                q.pop();
                if(ch == 'D'){
                    if(r > 0){
                        r--;
                    }else{
                        d++;
                        q.push(ch);
                    }
                }else{
                    if(d > 0){
                        d--;
                    }else{
                        r++;
                        q.push(ch);
                    }
                }
            }
            if(size == q.size()){
                break;
            }
        }
        return (q.front() == 'R')? "Radiant" : "Dire";
    }
};

// "DDDRRRRR"
// "RDD"
// "RRDDDRRR"
// "RRDDDDDDRDDRRRR"
// "DRRDRDRDRDDRDRDR"
// "DDRRR"
// "RDRDRDDRDRDRDRDRRDRDRDRDRDRDDDDRRDRDRDRDRDRDRDRRRRRDRDRDRDRDDDDDRDRDRDRDRDRDRDRRDRDRDRDRDRDRRDRDRDRDRDRDRDRDRRDRDRDRDRDRRD"
// "RRDDDDDDDRRDRRDDRRRR"
// "RDRDRDDRDDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRDDDDDDRRDRRDDRRRRRDRDDDDDDDRRDRRDDRRRRRDRRDRDRDDDDDDDRRDRRDDRRRRRDRDRDDDDRRDRDRDRDRDRDRDRRRRRDRDRDRDRDDDDDRDRDRDRDRDRDRDRRDRDRDRDRDRDRRDRDRDDDDDDDRRDRRDDRRRRRDRDRDRDRDRRDRDRDRDRDRRD"
// "DDR"
// "DDRRR"
// "DRRDRDRDRDDRDRDR"
// "RDRDRDDRDRDRDRDRRDRDRDRDRDRDDDDRRDRDRDRDRDRDRDRRRRRDRDRDRDRDDDDDRDRDRDRDRDRDRDRRDRDRDRDRDRDRRDRDRDRDRDRDRDRDRRDRDRDRDRDRRD"
