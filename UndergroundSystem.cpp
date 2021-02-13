// 1396. Design Underground System
// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> check_in; // check-in history of each traveler
    unordered_map<string, pair<int, int>> trip; // trip history of each pair of start and end stations

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(check_in.find(id) == check_in.end()) {
            return;
        }
        
        string startStation = check_in[id].first;
        string endStation = stationName;
        string tripName = startStation + "#" + endStation;
        
        int startTime = check_in[id].second;
        int endTime = t;
        int tripTime = endTime - startTime;
        
        check_in.erase(id);
        
        if(trip.find(tripName) == trip.end()) {
            trip[tripName] = {0, 0};
        }
        
        trip[tripName].first += tripTime; // update the total trip time
        trip[tripName].second ++; // increment the number of trips
    }
    
    double getAverageTime(string startStation, string endStation) {
        string tripName = startStation + "#" + endStation;
        
        if(trip.find(tripName) == trip.end()) {
            return 0;
        }
        
        int totalTime = trip[tripName].first;
        int numTrips = trip[tripName].second;
        
        return (double) totalTime / numTrips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */