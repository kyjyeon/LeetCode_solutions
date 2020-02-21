class Solution {
public:
    bool checkHappy(int n, int count, bool& happy) {
        ++count;
        if (count > 6)  //Happy is determined within 6 loop, so if the count is more than 6, just return the bool(happy)
            return happy;

        string str = to_string(n);  //change given integer to string to get seperated integer

        int len = str.length();
        int total = 0;
        for (int j = 0; j < len; j++) { 
            int num = str[j] - '0';
            total += int(pow(num, 2));
        }
        if (total == 1) {
            happy = true;
            return happy;
        }
        checkHappy(total, count, happy);

        return happy;
    }

    bool isHappy(int n) {
        bool happy = false; // flag for happy check
        int count = 0;
        if (n == 0)
            return happy;
        if (n == 1) {
            happy = true;
            return happy;
        }
        checkHappy(n, count, happy);

        return happy;
    }
};
