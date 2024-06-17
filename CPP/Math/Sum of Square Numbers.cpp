bool judgeSquareSum(int c) {
        // for (long i = 0; i*i <= c; i++) {
        //     for (long j = 0; j*j <= c; j++) {
        //         if (i * i + j * j == c)
        //             return true;
        //     }
        // }
        // return false;
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }
