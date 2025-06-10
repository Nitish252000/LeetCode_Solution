**▶️ Dry Run with n = 11 (1011)**
Initialize:
cnt = 0
n   = 11 → 1011

**1st iteration:**
n & 1 → 1011 & 0001 = 0001 → true

cnt++ → cnt = 1

n = n >> 1 → 1011 >> 1 → 0101 (5)

**2nd iteration:**
n & 1 → 0101 & 0001 = 0001 → true

cnt = 2

n >> 1 → 0010 (2)

**3rd iteration:**
n & 1 → 0010 & 0001 = 0000 → false

cnt = 2

n >> 1 → 0001 (1)

**4th iteration:**
n & 1 → 0001 & 0001 = 0001 → true

cnt = 3

n >> 1 → 0000 (0)

Now the loop ends.

**🧾 Final Count**
So, the number of 1 bits in 11 (1011) is 3.

✅ Output: 3
