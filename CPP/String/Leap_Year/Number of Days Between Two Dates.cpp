class Solution {
public:
    bool isLeap(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        return false;
    }
    int daysFromOrigin(string date) {
        int n = date.size();
        int ans = 0;
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int d = stoi(date.substr(8, 2));
        int m = stoi(date.substr(5, 2));
        int y = stoi(date.substr(0, 4));
        // Count days for complete year
        for (int i = 1; i < y; i++) {
            if (isLeap(i))
                ans += 366;
            else
                ans += 365;
        }

        // Count days for complete month
        for (int i = 1; i < m; i++) {
            if (i == 2 && isLeap(y))
                ans += 29;
            else
                ans += months[i - 1];
        }
        ans += d;
        return ans;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(daysFromOrigin(date1) - daysFromOrigin(date2));
    }
};
