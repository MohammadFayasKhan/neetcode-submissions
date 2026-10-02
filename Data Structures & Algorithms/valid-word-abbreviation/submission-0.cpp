class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, n = word.length(), m = abbr.length();

        while(i < n && j < m) {
            char w_c = word.at(i);
            char a_c = abbr.at(j);

            if(isdigit(a_c)) {
                if(a_c == '0') {
                    return false;
                }

                int curr = 0;

                while(j < m && isdigit(abbr.at(j))) {
                    curr = curr * 10 + (abbr.at(j) - '0');
                    j++;
                }

                i += curr;
            } else {
                if(w_c != a_c) {
                    return false;
                }
                i++; j++;
            }
        }

        return i == n && j == m;
    }
};