# Truth Tables and Bit Operations

- **AND** - When applied to two bits, both of the bits must be 1 to get a 1. Otherwise, we will get a 0. Represented using the `&` symbol.
- **OR** - When applied to two bits, only one of the bits has to be a 1 to get a 1. This means if both bits are 1, we will get a 1 and 0 if both bits are 0. Represented using the `|` symbol.
- **XOR** - When applied to two bits, we will get a 1 if only one of the bits is a 1. Otherwise, we will get a 0. Represented using the `^` symbol.
- **Negation** - Negation just flips the current bit. Negation of 0 is 1, and negation of 1 is 0. Represented using the `~` symbol.
- **Shifting Bits** - Shifting bits refers to shifting our bits, either to the left or to the right. It takes all of the bits and shifts them by one position either to the left or to the right. `>>` is a right shift and `<<` is a left shift.

> Technically speaking, shifting to the left means multiplying the given integer by 2 and shifting to the right means dividing the given integer by 2. Doubling and halving, respectively.

![hello](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/d6912f8f-cdf1-4dce-998e-35b44ff9d600/sharpen=1)

To demonstrate the above concepts, let's take 001 for example, which represents 1 in decimal.

Performing left shift three times will result in the following, where in the last operation, we truncate the `1` and replace it with a `0`.

**`001 << 1` = `010`**

`010 << 1` = `100`

`100 << 1` = `000`

The following demonstrates how we concluded `001` represents `1` in decimal. We can use this to convert any binary into decimal and any decimal into binary.

![hello](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/2b62ec4f-070a-49e4-39a5-7d2be7ad7300/sharpen=1)

**Below is the code representing what we discussed so far.**

```cpp
// AND
int n = 1 & 1;

// OR
n = 1 | 0;

// XOR
n = 0 ^ 1;

// NOT (negation)
n = ~n;

// Bit Shifting
n = 1;
n = n << 1;
n = n >> 1;
```

# Demonstration

Let us say that we are asked to count the number of `1` bits that are in the binary representation of the integer 23.

Using the above visual we showed, we derive that 23's binary representation is `10111`. To count the number of `1`s, we can keep shifting our bits to the right until we get all `0`s. The question is how do we know when to increment our count? We need a way to detect that our current bit is a `1`. Recall that `1 & 1 = 1`. So, if our current bit,`n`, results in `n & 1 == 1`, we can increment our count.

```cpp
// Counting Bits
int countBits(int n) {
    int count = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n = n >> 1; // same as n / 2
    }
    return count;
}
```

```markup
23 -> 10111

// First bit was a 1, increment count and shift to the right.
10111 & 00001 -> 00001

// First bit was a 1, increment count and shift to the right.

01011 & 00001 -> 00001

// We again get a 1, so increment count and shift to the right.

00101 & 00001 -> 00001

// We get a 0, so we only shift to the right, leaving the count untouched.

00010 & 00001 -> 00000

// We get a 1, so we shift to the right and increment the count.
00001 & 00001 -> 00001

```

From the above operations, we have a count of `4`.
