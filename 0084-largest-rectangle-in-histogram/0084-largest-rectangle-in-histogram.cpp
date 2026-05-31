class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nsl(n), nsr(n);
        stack<int>st;
        while(!st.empty()){
            st.pop();

        }
        for(int i = 0; i < n; i++){
            while(!st.empty()&& heights[st.top()] >= heights[i] ){
                st.pop();
            }
            nsl[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
    
      while(!st.empty()){
            st.pop();

        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty()&& heights[st.top()] >= heights[i] ){
                st.pop();
            }
             nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int maxarae = 0;
        for(int i =0; i< n; i++){
            int width = nsr[i] - nsl[i] - 1;
            int arae = heights[i]*width;
            maxarae = max(maxarae,arae);
        }
        return maxarae;
    }
};