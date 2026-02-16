//https://leetcode.com/problems/design-ride-sharing-system
class RideSharingSystem {
public:
    queue<int> rider, driver;
    unordered_set<int> s_rider;
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        s_rider.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty())
            return {-1, -1};
        vector<int> res;
        while(!rider.empty()){
            if(s_rider.count(rider.front())){
                res.push_back(driver.front());
                driver.pop();

                res.push_back(rider.front());
                s_rider.erase(rider.front());
                rider.pop();
                return res;
            }
            rider.pop();
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        s_rider.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
/*
["RideSharingSystem","addRider","cancelRider","addRider","addDriver","cancelRider","cancelRider","cancelRider","matchDriverWithRider","addRider","addDriver","addDriver","addRider","matchDriverWithRider","addRider"]
[[],[646],[646],[720],[200],[720],[289],[176],[],[314],[765],[954],[980],[],[388]]
*/
