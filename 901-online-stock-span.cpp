//https://leetcode.com/problems/online-stock-span
class StockSpanner {
public:
    stack<pair<int, int>> s;//val, span
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().first <= price){
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// ["StockSpanner","next","next","next","next","next"]
// [[],[6727],[9666],[581],[9185],[1695]]
// ["StockSpanner","next","next","next","next","next","next","next"]
// [[],[100],[60],[80],[60],[70],[60],[75]]
// ["StockSpanner","next","next","next","next","next","next","next","next"]
// [[],[100],[80],[60],[70],[60],[75],[85],[100]]
