# Bitwise Operators in C++
- In C+, Bitwise Operators are the operators that are used to perform bit-level operations on the integers. 
- While performing these operations, ***integers are considered as sequences of binary digits***.

## Bitwise AND (&):
  - Compares each bit; the result is 1 only if both bits are 1.
  - Example:
    7 & 4 (binary: 111 & 100 = 100 or 4).
## Bitwise OR (|):
  - Compares each bit; the result is 1 if at least one bit is 1.
  - Example:
    7 | 4 (binary: 111 | 100 = 111 or 7).
## Bitwise XOR (^):
  - Compares each bit; the result is 1 if the bits differ.
  - Example:
    7 ^ 4 (binary: 111 ^ 100 = 011 or 3).
## Bitwise NOT (~):
  - Inverts the bits of a single number.
  - Example:
    4 (binary: 100 = 011 or 3).
## Left Shift (<<):
  - Shifts bits to the left, equivalent to multiplying by 2<sup>number of positions</sup>.
  - Example:
    5 << 2 (binary: 101 becomes 10100 or 20).
## Right Shift (>>):
  - Shifts bits to the right, equivalent to dividing by 2<sup>number of positions</sup>.
  - Example:
    16 >> 2 (binary: 10000 becomes 000100 or 4).
