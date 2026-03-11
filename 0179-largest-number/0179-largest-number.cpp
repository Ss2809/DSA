class Solution {
public:
   static bool comp(string a, string b){
    return a+b > b+a;
   }
    string largestNumber(vector<int>& nums) {
        vector<string>st;
        for(auto i : nums){
            st.push_back(to_string(i));
        }
        sort(st.begin(), st.end(), comp);
        if(st[0] == "0") return "0";
        string ans = "";
        for(auto i : st){
            ans += i;
        }
        return ans;
    }
};