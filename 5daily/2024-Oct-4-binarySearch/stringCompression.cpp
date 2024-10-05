class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, index = 0;
        int n = chars.size();
        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            while (i < n  && chars[i] == currentChar) {
                i++;
                count++;
            }

            chars[index++] = currentChar;

            if (count > 1) {
                string count_str = to_string(count);
                for (auto it : count_str) {
                    chars[index++] = it;
                }
            }
        }

        return index;
    }
};