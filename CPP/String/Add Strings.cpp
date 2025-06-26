string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0) {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;

            int sum = x + y + carry;
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
            if (i >= 0)
                i--;
            if (j >= 0)
                j--;
        }
        if (carry > 0) {
            ans = to_string(carry) + ans;
        }
        return ans;
}
