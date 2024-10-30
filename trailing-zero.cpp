/*
Logic Recap:
The idea is to count how many times 5 appears as a factor in the numbers from 1 to 
𝑛
n, because each factor of 5 (paired with a factor of 2) contributes to a trailing zero.

The formula we use in each iteration is 
count
+
=
𝑛
𝑖
count+= 
i
n
​
 , where 
𝑖
i is powers of 5 (i.e., 
𝑖
=
5
,
25
,
125
,
…
i=5,25,125,…).

Dry Run:
First Iteration: 
𝑖
=
5
i=5
200
5
=
40
5
200
​
 =40
There are 40 multiples of 5 between 1 and 200 (i.e., 5, 10, 15, ..., 200).
Add 40 to count.
count = 40
Second Iteration: 
𝑖
=
25
i=25
200
25
=
8
25
200
​
 =8
There are 8 multiples of 25 between 1 and 200 (i.e., 25, 50, 75, ..., 200).
Each multiple of 25 contributes an extra factor of 5 (because 
25
=
5
×
5
25=5×5).
Add 8 to count.
count = 40 + 8 = 48
Third Iteration: 
𝑖
=
125
i=125
200
125
=
1
125
200
​
 =1
There is 1 multiple of 125 between 1 and 200 (i.e., 125).
Each multiple of 125 contributes another extra factor of 5 (because 
125
=
5
×
5
×
5
125=5×5×5).
Add 1 to count.
count = 48 + 1 = 49
Fourth Iteration: 
𝑖
=
625
i=625
200
625
=
0
625
200
​
 =0 (since 200 is smaller than 625, there are no multiples of 625 between 1 and 200).
No further factors of 5 are contributed.
count = 49
Conclusion:
The number of trailing zeros in 
200
!
200! is 49.

Steps Summary:
First, we count 40 multiples of 5.
Then, we count 8 multiples of 25 (which add an extra factor of 5).
Next, we count 1 multiple of 125 (which adds another extra factor of 5).
The loop stops when the divisor exceeds 
𝑛
n. Hence, the final count is 49.
Final Answer:
There are 49 trailing zeros in 
200
!
200!.
*/

#include <iostream>
#define int long long 
using namespace std;

int32_t main() 
{
    int n;
    cin >> n;

    int count = 0;

    // Count how many factors of 5 are in n!
    for (int i = 5; i <= n; i *= 5) 
    {
        count += n / i;
    }

    cout << count << endl;

    return 0;
}
// for ex ->   n = 200 
// phele deekha ke power of 5 kitne hai voh nikle ( 200 / 5 =  40 )
/*
There are 40 multiples of 5 between 1 and 200 (i.e., 5, 10, 15, ..., 200).
Add 40 to count.
count = 40
*/

// ab deekhte hai 25 seah divide kitne honge(  means multiple of 25 ) 200 / 25 =  8 
/*

There are 8 multiples of 25 between 1 and 200 (i.e., 25, 50, 75, ..., 200).
Each multiple of 25 contributes an extra factor of 5 (because 

Add 8 to count.
count = 40 + 8 = 48

*/

// similarly itterate for all the ( 5 * i ) which are less than n 