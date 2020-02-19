class Solution {
public:
    bool checkHappy(int n, int count, bool& happy) {
        ++count;
        if (count > 6)
            return happy;

        string str = to_string(n);

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
        bool happy = false;
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