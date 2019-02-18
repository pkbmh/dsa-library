#include "../../../common/headers.hpp"


/*
The problem is to count all the possible paths from top left to 
bottom right of a mXn matrix with the constraints that from each 
cell you can either move only to right or down.

given matrix of n * m
we have to take n-1 steps down and m-1 steps right.
these steps can be taken in any permutation of these setps 
(Using combinatorics) In this approach We have to calculate 

C(m+n-2, n-1) here which will be (m+n-2)! / (n-1)! (m-1)!

*/