double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        // Handle negative power
        if (n < 0) {
            if (n == INT_MIN) {
                x = 1 / x;
                n = INT_MAX; // to avoid overflow in negation
                return x * myPow(x, n);
            } else {
                x = 1 / x;
                n = -n;
            }
        }
        // Recursively calculate the power
        double half = myPow(x, n / 2);
        
        // If n is even
        if (n % 2 == 0) {
            return half * half;
        } else {
            // If n is odd
            return half * half * x;
        }
}
