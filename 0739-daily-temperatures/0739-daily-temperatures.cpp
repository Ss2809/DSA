class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //same logic next geather ele okay 

        //step1
        stack<int>st;
        int n = temp.size();
        vector<int> ans(n, 0);
        

        //step2
        for(int i = n-1; i>= 0; i-- ){
            while(!st.empty() && temp[st.top()] <= temp[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top()-i;
            }

            st.push(i);
        }
        // step 3
        return ans;
    }
};