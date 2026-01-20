# **Bitwise operators** in Java perform operations directly on the binary representation of integer values (e.g., int, long, short, byte, char).

_**Main Bitwise Operators**_
  & (Bitwise AND): Returns 1 if both corresponding bits are 1, otherwise 0. 
  | (Bitwise OR): Returns 1 if at least one corresponding bit is 1, otherwise 0. 
  ^ (Bitwise XOR): Returns 1 if corresponding bits are different, otherwise 0. 
  ~ (Bitwise Complement): Inverts all bits (0 becomes 1, 1 becomes 0). In Java, this uses two’s complement, so ~n equals -(n + 1). 

_**Shift Operators**_
  << (Left Shift): Shifts bits left by specified positions; equivalent to multiplying by 2^n. 
  >> (Signed Right Shift): Shifts bits right, filling the leftmost bit with the sign bit (preserves sign). 
  >>> (Unsigned Right Shift): Shifts bits right, filling the leftmost bit with 0 (always positive result). 

_**Key Use Cases**_
  Checking even/odd numbers: Use n & 1 — returns 1 if odd, 0 if even. 
  Swapping variables without a temp: Use XOR: a ^= b; b ^= a; a ^= b;. 
  Setting/clearing flags: Use | to set, & ~mask to clear specific bits. 
  Efficient multiplication/division by powers of two: Use << (multiply) or >> (divide). 
