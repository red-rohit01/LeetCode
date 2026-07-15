class Solution {
public:
    // The sum of the first n odd numbers is a perfect square (n²), and the sum of the first n even numbers is n(n+1). Since n and n+1 are consecutive integers, they are always coprime — so the GCD collapses down to just n.

    // Approach
    // Sum of first n odd numbers: 1 + 3 + 5 + ... + (2n-1) = n²
    // Sum of first n even numbers: 2 + 4 + 6 + ... + 2n = n(n+1)
    // We need gcd(n², n(n+1)).
    // Factor out n: gcd(n², n(n+1)) = n * gcd(n, n+1).
    // Since n and n+1 are consecutive integers, gcd(n, n+1) = 1.
    // Therefore the result simplifies to just n.
    // No actual GCD computation or loop is needed — the answer is always n
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};