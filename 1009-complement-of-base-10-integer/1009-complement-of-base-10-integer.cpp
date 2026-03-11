class Solution {
public:
    int bitwiseComplement(int n) {
      if(n == 0){
        return 1;
      }
        string bin = "";

     
        while (n > 0) {
            int bit = n % 2;
            bin = char(bit + '0') + bin;
            n /= 2;
        }

       
        for (int i = 0; i < bin.length(); i++) {
            if (bin[i] == '0')
                bin[i] = '1';
            else
                bin[i] = '0';
        }

        
        int ans = 0;

        for (int i = 0; i < bin.length(); i++) {
            ans = ans * 2 + (bin[i] - '0');
        }

        return ans;
    }
};