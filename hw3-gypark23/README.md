1.
	i. C uses binary to store information on memory. All information is either 0 or 1, and it is stored in memory.
	   C uses decimal system for presentation and output for human. Although calculations may be in binary, the final output is in decimal system
	   for easier reading for human.
	   C uses hexadecimal system to define the memory location. The memory address is written in hexadecimal system.

	ii.The number is first done % by 2 to check if the remainder is 1 or 0. This will be the first binary digit. 
	   Then, the number will be divided by 2 to proceed to the next digit calculation. The number is then done % by 2 once again
	   and whatever the remainder is becomes the second binary digit.
	   The procedure is repeated (%2 and /2) until the number can no longer be divided.
	   For example, if a number is 15, first 15%2 is done, which is 1. 1 goes to the lowest digit.
	   Then, 15/2 = 7, and 7%2 is done, which is 1. 11 so far,
	   7/2 = 3, 3%2 = 1, so 111 so far,
	   3/2 = 1, 1%1 = 1, so 1111 so far,
	   and since 1/2 = 0, and 0%2 = 0, it would be 01111, which is basically 1111.
	   This is demonstrated in 1_dec2bin.c


	iii. For hexadecimal to decimal, you could just multiply each digit with 16^digit number and add them all. This is also demonstrated in my 1_dec2bin.c
	     I added a new function hexadecimal_to_dec to demonstrate this




2.	Iteration and recursion "both execute a set of instructions repeatedly" in a given rule. However, recursion repeatedly calls
	a method call that is called by the same method call. If a function calls itself and does a job repeatedly, that is recursion. 
	Recursion could be handy since the code may be shorter and smaller, and it is easier to work with. However, it may be inefficient in terms of
	memory space and resource allocation since it calls the function over and over again.
	Iteration is a loop that is repeatedly executed until the condition is met. While it may call another function or method, it doesn't
	necessarily repeats itself or calls a method again itself. The iteration may be longer than recursion, but it is memory-efficient since it does not
	have to call unnecessary parts over and over again, but just the parts that need to be repeated. 
	(Source: https://medium.com/backticks-tildes/iteration-vs-recursion-c2017a483890#:~:text=The%20concept%20of%20Recursion%20and,a%20certain%20condition%20is%20met.)


