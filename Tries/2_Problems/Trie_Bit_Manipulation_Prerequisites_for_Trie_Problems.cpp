/*
Problem: Bit Manipulation Prerequisites for Trie Problems
Link: 
Difficulty: 
Approach: 
Time Complexity: 
Note:
    
*/

/*
========================================
BIT MANIPULATION - QUICK NOTES (C++)
========================================

1. BINARY REPRESENTATION
------------------------

Computers store everything in binary (0s and 1s).

Each bit represents a power of 2.

Example:
Decimal: 13

Bit position:  3 2 1 0
               | | | |
Binary:        1 1 0 1

Value = 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0
      = 8 + 4 + 0 + 1 = 13

------------------------------------------------------------

Common integer sizes in C++ (almost always):

int        -> 32 bits  (4 bytes)
long long  -> 64 bits  (8 bytes)

(Note: long is platform-dependent. In competitive programming,
you'll mostly use int and long long.)

Ranges:

int
-2^31 to 2^31 - 1
= -2147483648 to 2147483647

long long
-2^63 to 2^63 - 1

Unsigned types have no sign bit, so they store only non-negative
numbers and have a larger positive range.

------------------------------------------------------------

Bits are indexed from RIGHT to LEFT.

Example:

13 = 1101

Index: 3 2 1 0
Bits : 1 1 0 1

Bit 0 = Least Significant Bit (LSB)
Highest bit = Most Significant Bit (MSB)

============================================================
2. XOR (^)
============================================================

Truth Table:

0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

Rule:
Result is 1 if the bits are DIFFERENT.
Result is 0 if the bits are SAME.

Equivalent way to remember:
XOR = odd number of 1s.

Examples:

0 ^ 0 -> zero 1s -> even -> 0
0 ^ 1 -> one 1  -> odd  -> 1
1 ^ 0 -> one 1  -> odd  -> 1
1 ^ 1 -> two 1s -> even -> 0

------------------------------------------------------------

Properties (VERY IMPORTANT)

a ^ 0 = a

a ^ a = 0

a ^ b ^ a = b
(order doesn't matter because XOR is associative and commutative)

Useful for:
- Finding the unique element.
- Swapping numbers (rarely used now).
- Trie XOR problems.
- Prefix XOR.

Example:

5 ^ 5 = 0

7 ^ 0 = 7

============================================================
3. CHECK IF i-th BIT IS SET
============================================================

Method 1 (Striver's method)

(num >> i) & 1

Explanation:

Step 1:
Right shift by i positions.

num >> i

This brings the i-th bit to position 0.

Step 2:
AND with 1.

Only the last bit remains.

Example:

num = 13

1101

Check bit 2:

1101 >> 2
= 0011

0011 & 0001
= 0001

Answer = 1
Bit is SET.

------------------------------------------------------------

If answer == 1
-> bit is set.

If answer == 0
-> bit is not set.

Example:

if ((num >> i) & 1)
{
    // i-th bit is set
}

============================================================
4. SET THE i-th BIT
============================================================

Formula:

num | (1 << i)

Explanation:

1 << i

Creates a number with ONLY the i-th bit equal to 1.

Example:

i = 3

1
0001

1 << 3

1000

Now OR it with the number.

Example:

num = 5

0101

Mask:

1000

OR:

0101
1000
----
1101

Result = 13

Even if the bit was already 1, OR keeps it as 1.

============================================================
EXTRA OPERATIONS (GOOD TO KNOW)
============================================================

Unset (clear) i-th bit

num & ~(1 << i)

Reason:
Create a mask with every bit = 1 except i-th bit = 0.
AND clears only that bit.

------------------------------------------------------------

Toggle (flip) i-th bit

num ^ (1 << i)

0 becomes 1
1 becomes 0

------------------------------------------------------------

Left shift

num << i

Means:
Multiply by 2^i (if no overflow).

Example:

5 << 2

5 * 4 = 20

------------------------------------------------------------

Right shift

num >> i

Means:
Integer divide by 2^i (for non-negative numbers).

Example:

20 >> 2

20 / 4 = 5

============================================================
COMMON BIT MASKS
============================================================

1 << 0 = 0001
1 << 1 = 0010
1 << 2 = 0100
1 << 3 = 1000
...

Each mask has exactly one bit set.

============================================================
COMPLEXITIES
============================================================

Check bit   -> O(1)
Set bit     -> O(1)
Clear bit   -> O(1)
Toggle bit  -> O(1)
Shift        -> O(1)

============================================================
MOST IMPORTANT FORMULAS TO MEMORIZE
============================================================

Check bit:
(num >> i) & 1

Set bit:
num | (1 << i)

Clear bit:
num & ~(1 << i)

Toggle bit:
num ^ (1 << i)

XOR facts:
a ^ a = 0
a ^ 0 = a
XOR = 1 when bits are different
*/