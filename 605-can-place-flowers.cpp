//https://leetcode.com/problems/can-place-flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int index = 0;
        if(flowerbed.size() == 1 && flowerbed[0] == 0){
            return (n > 1)? false: true;
        }
        while(index < flowerbed.size() && n != 0){
            if(flowerbed[index] == 1){
                index = index + 2;
            }else{
                if(index != 0 && flowerbed[index-1] != 1 && (index+1) < flowerbed.size() && flowerbed[index+1] != 1){
                    n--;
                    index = index + 2;
                }else if(index == 0 && (index+1) < flowerbed.size() && flowerbed[index+1] != 1){
                    n--;
                    index = index + 2;
                }else if((index+1) == flowerbed.size() && index != 0 && flowerbed[index-1] != 1){
                    n--;
                    index = index + 2;
                }else{
                    index++;
                }
            }
        }
        return (n > 0)? false: true;
    }
};

// [0,0,1,0,0]
// 1
// [0,0,1,0,0]
// 2
// [0,0,0,0,0]
// 3
// [1,0,0,0,1]
// 1
// [1,0,0,0,1]
// 2
// [1,0,0,0,1]
// 1
// [0,0,1,0,0]
// 1
// [0,0,1,0,0,0,0,0,1,0,0]
// 4
// [1,0,0,0,0,0,1]
// 2
// [1,0,0,0,0,1]
// 2
// [1]
// 1
// [1]
// 0
// [0]
// 0
// [0]
// 1
// [0,0,1]
// 1
// [1,0,0]
// 1
// [0,0,1,0,0]
// 2
// [0]
// 1
// [1,0,0,0,0,0,1]
// 2
// [0,0,1,0,0,0,0,0,1,0,0]
// 4
// [1,0,0,0,1]
// 1
// [1,0,0,0,1]
// 2
// [1,0,0,0,1]
// 1
// [0,0,1,0,0]
// 1
// [0,0,1,0,0,0,0,0,1,0,0]
// 4
// [1,0,0,0,0,0,1]
// 2
// [0]
// 1
// [1,0,0,0,0,1]
// 2
// [1,0,0,0,1]
// 1
// [1,0,0,0,1]
// 2
// [0,0,1,0,0]
// 1
// [1,0,0,0,1]
// 1
