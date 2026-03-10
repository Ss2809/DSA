class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuel = 0;
        int diff = 0;
        int totaldiff = 0;
        int index = 0;
        for(int i = 0; i < gas.size(); i++){
            diff = gas[i]-cost[i];
              totaldiff += diff;
            fuel += diff;
              if(fuel < 0){
                fuel= 0;
                index = i+1;
              }
        }
        if(totaldiff < 0) return -1;
        return index;
    }
};