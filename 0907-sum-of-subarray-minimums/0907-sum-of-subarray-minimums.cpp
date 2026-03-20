class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nge(n), pgt(n);
        stack<int>st;

        //step1
        for(int i = 0; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();

            st.push(i);
        }
       while(!st.empty()) st.pop();

        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) pgt[i] = n;
            else pgt[i] = st.top();

            st.push(i);
        }

        // step 2
        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i< n; i++){
            int left  = i- nge[i];
            int right = pgt[i]-i;
           ans = (ans + (1LL * arr[i] * left * right) % mod) % mod;
        }
        return ans;
    }
};