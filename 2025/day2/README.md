## Day 2: Gift Shop

**Time complexity:**
- **Part 1:** O(N · D)
- **Part 2:** O(N · D²)

Where
`N` = total number of product IDs across all ranges
`D` = number of digits in a product ID (≤ 10 for uint32_t)

**Space complexity:**
O(1) auxiliary space (excluding output storage)

**Solution:**
```
Part #1: 9188031749
Part #2: 11323661261
```

### Approach
The input consists of numeric ranges of product IDs. Each ID is validated independently by converting it to a string and checking for repeated digit patterns.

- **Part 1:**
An ID is invalid if its digit string has even length and the first half exactly matches the second half.

- **Part 2:**
An ID is invalid if any substring (of length ≥ 1) can be repeated to reconstruct the full digit string.

For both parts, all IDs in all ranges are scanned, invalid IDs are collected, and their values are summed.

This brute-force approach is sufficient because product IDs are small and bounded, keeping digit counts low.

### Concepts
- String pattern repetition
- Brute-force range scanning
- Const-correctness in C++
- Simple algorithmic validation over optimization