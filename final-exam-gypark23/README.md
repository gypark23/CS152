1.
	i. Key difference between stack and queue is that stack uses LIFO principle, which means that
	the last inserted element is the first element that comes out. Queue uses FIFO principle,
	where first inserted element comes out first. Also, insertion and deletion for stack only occurs
	at the frontmost part of the stack, whereas insertion and deletion takes place in the end of the stack.
	They are similar in the way that they are both linear data structures and that they are abstract data types,
	which means the programmer has liberty in choosing the implementation. They both can be implemented
	by an array or linked list.
	
	Since Queue uses FIFO, queue implementation could be beneficial when
	things don't have to be processed immediately and could be wait. This is useful when resource is shared among
	other consumers, by creating a queue of waiting consumers. Similarly, for this reason, queue is used in the operating system
	for ready queue. For example, when a user requests to print multiple PDFs, OS will create a queue for the printer, where first print request
	is printed first, and goes on.
	Psuedocode would be
	
	PrintQueue
	{
	Print(head of Queue)
	Enqueue
	}(while Queue is empty)


	Stack is LIFO, which could be useful in backtracking program. Backtracking is an algorithm
	that finds the optimal solution by trying the possible candidates and removing invalid solutions. Famous example is 
	N-Queens problem, calculating safe positions for n amounts of queen pieces.
	Stack could be uesd to record the location of the queens on the board.
	If the location of a queen is not an optimal solution, the queen at the top of the stack will be popped,
	and another position of that queen is tried, pushed to the stack. Trial, popping and pushing repeats until the solution is found.
	Psuedocode would be 

	Create empty stack and start placing pieces
	while (solution not found) repeats for all positions until valid position found:
	{	
		if (valid position found)
		{
			push the position to stack, move to next row
		}

	   else
	   {
		  if (stack empty)
			break and stop search
		  else
			pop stack, try other positions
	   }

	   if solution found
	   {
		  pop stack, set current position to next position
		  backtrack to find next solution
	   }
   }

   P.S. I tried to explain it as clear as possible, but with my language proficiency it was a bit challenging, so forgive me
   if this explanation was a bit bizarre. 

	source(http://www.cs.albany.edu/~sdc/CSI310/Spr03/Lectures/L18/hand07.pdf)
	(https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/)
	(https://www.studytonight.com/data-structures/queue-data-structure#:~:text=Applications%20of%20Queue&text=Serving%20requests%20on%20a%20single,interrupts%20in%20real%2Dtime%20systems.)
	(http://mathcenter.oxford.emory.edu/site/cs171/nQueensProblemAndBacktracking/)

	ii. a) O(n), since it has to go through the linked-list to search and at the worst case where the element is the last, repeats n times
		b) O(n), linking a new node to the last node itself is just O(1). However, it might take longer if the last node has to be found, which takes O(n).
		c) O(n), similar to b), deleting a node itself is O(1), but the last node has to be accessed, therefore is O(n)
		d) average O(log n), binary search tree uses binary search method, which reduces the options by half, therefore is O(log n).
		If a tree is skewed, the worst case scenario is O(n) where the tree is basically a linked list 
		e) average O(log n) for the same reason above, but at the worst case where the tree is skewed and the element is to be added to the last,
		insertion is O(n) since it has to traverse all elements
		f) average O(log n) for the same reason above, but at the worst case where the tree is skewed and the last element is deleted,
		deletion is also O(n) since it also has to traverse all elements
		g) O(n), program doesn't know exactly which node to visit so at the worst case it has to visit all nodes.
		h) O(log n), when inserted it goes through log n comparison since the index gets divided by half every single comparison
		i) O(log n), at the worst case, deletion replaces the leaves to the root, swapping the children. This happens every floor, so the time
		complexity is the height, which is log n.
		j) O(1) since hash could be easily found with key, but at the worst case, O(n),if there are too many elements in a same key, looking in the key will take O(n).
		k) O(1), generating hash takes constant time complexity, but if hash collision happens, at the worst case, O(n).
		l) O(1), easily could delete with constant time complexity with known key or hash, but at the worst case where hash collision happens, O(n)
		source:https://www.bigocheatsheet.com/



4.	4c. fourbonacci time complexity is 4^n. Draw a recursion tree, and T(n) = T(n-1) + T(n-2) + T(n-3) + T(n-4) + C. This is essentially T(n) = O(4^(n-1)) + O(4^(n-2)) + O(4^(n-3)) + O(4^(n-4)) + C.
If these are broken down to the end, it reaches to 4^(n-1) + C, since there are four parts that are called recursively
(n-1), (n-2), (n-3), (n-4). Constant +C is dropped and n-1 is essentially n at large n value, so O(4^n).
There is a forloop that repeats n times for file writing. However, 4^n >>>> n for sufficiently large n, so time complexity is
4^n. O(4^n).