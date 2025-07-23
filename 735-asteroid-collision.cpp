// https://leetcode.com/problems/asteroid-collision

//concept for this problem is that
// we need positive value before negative for a collision.
// if the absolute value negative value is higher than previous positive value,
// we need to keep checking previous of that one and so on...

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto val: asteroids){
            if(s.empty()){
                s.push(val);
            }else{
                bool flag = false;
                while(val < 0 && !s.empty() && s.top() > 0){
                    if(abs(s.top()) == abs(val)){
                        flag = true;
                        s.pop();
                        break;
                    }else if(abs(s.top()) > abs(val)){
                        flag = true;
                        break;
                    }else{
                        s.pop();
                    }
                }
                if(!flag){
                    s.push(val);
                }
            }
        }

        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto val: asteroids){
            if(s.empty()){
                s.push(val);
            }else{
                if(val < 0 && s.top() > 0){
                    if(abs(s.top()) == abs(val)){
                        s.pop();
                    }else if(abs(s.top()) > abs(val)){
                        continue;
                    }else{
                        s.pop();
                        s.push(val);
                    }
                }else{
                    s.push(val);
                }
            }
        }

        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        if(asteroids.size() == res.size())
            return asteroids;
        reverse(res.begin(), res.end());
        return asteroidCollision(res);
    }
};

// [-2,2,-1,-2]
// [1,-2,10,-5]
// [4, -6]
// [-4,6]
// [5,10,-5]
// [8,-8]
// [10,2,-5]
// [-1,-2,2,1]
// [-4,-1,10,2,-1,8,-9,-6,5,2]
// [-1,-1,1,-1,5]
// [-1,1,-2,2,-3,4]
// [-8,10,-12, 9] 
// [46, -36, 3, 39, 20, -33, 35, 4, -26, -37, 27, -50, -23, 48, 5, -1, 29, -34, 34, 11, 22, 8, 41, -20, -10, 17, 35, -14, -9, 3, 12, -13, -47, 23, -39, 25, -43, -2, 26, -26, -42, -5, -4, 34, 3, 25, 20, 27, -6]
