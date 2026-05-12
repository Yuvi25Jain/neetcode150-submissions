class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // Sort by position descending
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double currFleetTime = 0;
        
        for (auto &car : cars) {
            double t = car.second;
            if (t > currFleetTime) {
                fleets++;            // new fleet
                currFleetTime = t;   // update leader time
            }
            // else merge into current fleet
        }
        
        return fleets;
    }
};
