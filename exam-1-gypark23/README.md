1.	Question 1
	i. Essentially, the standard int we use is signed integer, which can hold up to +- 2^31-1 for 32 bit.
	(https://stackoverflow.com/questions/12952553/difference-between-int-and-signed-int-declaration)
	Signed integer and integer can be used interchangably therefore. In C, an int type is signed by default.

	int a = 0; is essentially signed int a = 0; and they will work the same way in C.

	Unsigned int, however, unlike those two signed integer and integer, cannot express negative number.
	They are "unsigned", but ranges from 0 to 2^32-1. The range for signed integer and unsigned integer are the same,
	but it is shifted on the number line. For this reason, unsigned integer can expres higher positive values compared to
	signed integer.
	(https://www.thoughtco.com/definition-of-unsigned-958174#:~:text=An%20unsigned%20variable%20type%20of,4%2C294%2C967%2C295%20or%20about%204%20billion.&text=The%20range%20is%20the%20same,shifted%20on%20the%20number%20line.)

	Both signed and unsigned integers can express from 0 to 2^31 - 1, and only signed integer can express below that,
	and only unsigned integer can express over that.

	To declare an unsign integer, you can do it like this: unsigned int a = 0;



	ii. It prints out 4294967295. This is 2^32-1. This is because unsigned integer attempts to go back one from 0
	and it ends up to the greatest value of unsigned int.




2.	Question 2
	i. While-do and do-while are both iterations. They execute the iterations in do until the condition in while is matched.
	The key difference is the while-do checks the condition first and then iterates the iteration, and do-while first iterates
	and then checks the condition. Syntaxwise, this makes sense given that while-do has while first written before do, and do-while
	has do written before while.





4.	Question 4
	i.
		15
		15
		syntax error
		16
		225
		0

	ii. 
		1
		0
		1
		0
		0
		1
	

6.	Question 6
	To convert a decimal number into hexadecimal representation, you could run a do-while loop that does the following.
	Since hexadecimal representation contains letters from A to F, it should return char[] not int.
	In this loop, you could first find the remainder when n is divided by 16, or n%16. The remainder is the first digit of the hexadecimal form
	of the number. This will be stored in the first element of char[]. Then, The original number n is divided by 16, with decimals dropped. 
	The number divided by 16 becomes the new n, and n%16 is stored to the second element of char[], and then divided by 16. This process is repeated
	until n/16 = 0 and n becomes 0. This do-while loop can terminate when n==0. Then, since each digits are stored in the array backward,
	(this is because the lowest digit was stored to the first element of array), you could either print out the array backward by for loop 
	and it will print out the hexadecimal form of the decimal number, or just flip the array.

	In case of 2020:
	2020%16 = 4 (first digit)
	2020/16 = 126
	126%16 = 14 = E (second digit)
	126/16 = 7
	7%16 = 7 (third digit)
	7/16 = 0 (the loop terminates)
	2020 -> 7E4

	In case of 13:
	13%16 = 13 = D (first digit)
	13/16 = 0 (the loop terminates)
	13 -> D

	In case of 4199999:
	4199999%16 = 15 = F (first digit)
	4199999/16 = 262499
	262499%16 = 3 (second digit)
	262499/16 = 16406
	16406%16 = 6 (third digit)
	16406/16 = 1025
	1025%16 = 1 (fourth digit)
	1025/16 = 64
	64%16 = 0 (fifth digit)
	64/16 = 4
	4%16 = 4 (sixth digit)
	4/16 = 0 (the loop terminates)
	4199999 -> 40163F




10.	Question 10
	Array and linked list both store linear data. However, array is homogenous and contiguously located in memory, which means it
	is allocated in memory at compile time through static memory allocation.
	Because of this, array is inflexible and fixed. Array supports random access, so the elements of array could be accessed
	easily by indexing. The runtime for finding an nth element is O(1), well demonstrating its efficiency.
	RGB image is one of the example array is used. RGB image uses n*n*3 array to store color information of a picture.

	Linked list, unlike array, data isn't necessarily stored in consecutive manner. It has more freedom in memory, since new elements
	could be stored anywhere in memory. Therefore, size of linked list is variable, which could be beneficial compared to array.
	Linked list doesn't support random access, but supports	sequential access.
	Unlike array, linked list cannot access elements by indexing, and has to traverse through the nodes instead. 
	The time complexicity for finding an nth element is O(n), less efficient than that of array. An example of linked list used in programming
	is web-browsers	when it creates a linked list of webpages visited. Because websites are linked to each other and could be traversed 
	via URL, webbrowsers use linked list to record webpages visited. It also is beneficial since the size of it increases everytime
	another website is visited.

	(source: https://www.studytonight.com/data-structures/linked-list-vs-array)
	(source: https://www.quora.com/Where-are-linked-lists-used-in-real-life)
	(source: https://www.quora.com/Where-can-arrays-be-used-in-real-life)


