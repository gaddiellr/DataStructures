// Summation from 1 to n functions
// Gaddiel Lara Roldán
// 27/08/2022

#ifndef ACTIVITY_H
#define ACTIVITY_H

// Function: summation from 1 to n using an iterative method
// Parameter: a positive integer n
// Output: the summation from 1 to n
unsigned int iterativeSum(unsigned int n) {
    int sum = 0;                                     //    O(1)
    for (int i = 1; i <= n; i++) {                   //    O(n)
        sum += i;
    }
    return sum;                                      //    O(1)
}
// Complexity: O(1) + O(n) + O(1) = O(n) + O(2)


// Function: summation from 1 to n using a recursive method
// Parameter: a positive integer n
// Output: the summation from 1 to n
unsigned int recursiveSum(unsigned int n) {
    if (n == 0) {                                    //    O(1)
        return 0;
    }
    else return n + recursiveSum(n - 1);             //    O(1)
}
// Complexity: O(1) + O(1) = O(2)


// Function: summation from 1 to n using a direct mathematical method
// Parameter: a positive integer n
// Output: the summation from 1 to n
unsigned int directSum(unsigned int n) {
    return n * (n + 1) / 2;                          //    O(1)
}
// Complexity: O(1)

#endif /* ACTIVITY_H */
