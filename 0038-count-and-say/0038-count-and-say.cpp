class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        if(n == 2) return "11";

        string s = "11";
        for(int i=3; i<=n; i++){ // loop to iterate n
            string temp = "";
            s += '%'; //extra character to handle the last charcter count
            int cnt= 1;
            for(int j=1; j<s.size(); j++){ // to create next sequence of character
                if(s[j] != s[j-1]){
                    temp += to_string(cnt);
                    temp += s[j-1];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }

            s = temp;


        }

    return s;
    }


};