1. Repeats for n times as for loop iterates, so O(n)
O(n)

2. There are three loops inside each other which all iterates n times.
Since the loop is connected to each other and not separate, O(n) = n^3 not 3n.
O(n^3)

3. O(n) for selecting random number in an array of sized n is 1
since selecting random index number itself is O(1) and accessing the array element is also O(1).
It repeats twice, but they repeat separately. The whole process is basically a constant, so O(1).
O(1)

4. O(n) ignores constant, and declaring 250 variables are mere constants of +250 (like +C in calculus),
so runtime complexicity is 1.
O(1)

5. If you simply goes through the array and compare the values, which is linear search,
at the worst case where t is in the last element of the array, the program must go through the entire array. The array
size is n, so the time complexicity for scanning through the array is n. O(n).
If the array is sorted, multiple searches could be used.
For example, selection sort has o(n^2), merge sort has O(n*logn), linear search has O(n) and 
binary search has the complexicity of O(log n). 
(source: https://python-textbok.readthedocs.io/en/1.0/Sorting_and_Searching_Algorithms.html)

6. Assuming that linear search was used, at the worst case, t will be located at arr_m[n] and
must go through all elements in all of the arrays. Scanning through
one array has n time compexicity (since it has length of n), and there are m arrays total so n*m. 
O(nn).
If other search methods are used, simply the runtime is O(n) = m * (runtime of the chosen searching algorithm).
For example, if binary search was used, runtime is O(mlog(n))

7. Draw a recursion tree, and T(n) = T(n-1) + T(n-2) + T(n-3) + T(n-4) + C. This is essentially
T(n) = O(4^(n-1)) + O(4^(n-2)) + O(4^(n-3)) + O(4^(n-4)) + C. If these are
broken down to the end, it reaches to 4^(n-1) + C, since there are four parts that are called recursively
(n-1), (n-2), (n-3), (n-4). Constant +C is dropped and n-1 is essentially n at large n value, so
O(4^n).

8. There are n length of characters and m amount of characters. Two for loops could be run, one for password[n]
and character[m]. Character for loop is inside the for loop of scanning through the letters.
So, at the worst case where the password is the last letter, for each letter it will loop m times, and this will
happen n times for n letters. Therefore, the runtime is O(n) = m^n

9. Theoretically at the worst case the program never terminates if yellow is never randomly picked by the program.
So the runtime complexity is theoretically infinite.
O(infinite)

10. f(n) = f(n-1) + f(n-2) + f(n-3). Similar to 7, draw a recursive tree and they break down to three parts
since the three functions call themselves recursively. T(n) = O(3^(n-1)) + O(3^(n-2)) + O(3^(n-3)).
T(n) = 3^(n-1) + C, and big O notation is
O(3^n) by dropping constant +C and +1 which is negligible at large value of n
O(3^n).

11. This is essentially similar to the binary search method, although the program is designed to 
guess and check square root. For each iteration, the size of the data set gets reduced by half
after comparing the square of the guess value and the input. Computing the square and comparing the values are
constants, and do not affect (or merely) the runtime. The dominating part of the function here is 
binary search part, where n gets reduced by n/2. T(n)=T(n/2)+C, use Master's Theorem and the runtime complexity is
O(log n). (which is the same with binary search runtime).

12. For calculating a height of the BST, the program will visit every single node to calculate the height.
Calculating a height of an individual node is simply O(1), since all you have to do is just increment the counter.
There is no such thing as worst case scenario, for it will always visit all the nodes,
and incrementing the counter will repeat for n times for n amount of nodes.
Therefore, the runtime complexity is O(n).
O(n)