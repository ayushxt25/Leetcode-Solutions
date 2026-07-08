class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double slowest = 0;
        
        for (auto& car : cars) {
            if (car.second > slowest) {
                fleets++;
                slowest = car.second;
            }
        }
        
        return fleets;
    }
};