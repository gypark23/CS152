# Place your answers here!

1. "hello world"


2. C is a middle language, which means that C can be used as both high-level and low-level.
   Because of this property,it can be used to script drivers and kernels with low-level programming,
   while also script software applications using high-level programming.
   With this property, C is widely used in OS development, where kernel and drivers as well as software applications are necessary.
   (Source: https://www.geeksforgeeks.org/benefits-c-language-programming-languages/#:~:text=C%20is%20highly%20portable%20and,and%20applications%20requiring%20calculations%2C%20etc.)

   Compared to other programming languages, C gives a bit more authority to programmers--that is, it lets programmers manage tiny details
   of a program such as memory allocation. While this may be an advantage, in some cases, it might be a bit risky.
   Java, on the otherhand, lets programs run on its virtual machine, reducing risks of a program messing up a whole memory.
   For this reason, on mobile devices, especially Android, apps are built in Java rather than C. Apps built in Java are more "secure"
   in the way that one bad app cannot take down the whole OS, whereas one bad C app might screw up the whole OS.
   (Source: https://www.quora.com/Why-is-Java-preferred-for-developing-an-Android-app)


3. 
   A. This line tells you to include the headerfile stdio.h to the program for the input/output operations.
   B. Here you define the "main" function that will be executed once the program starts. It defines the main function as an integer type.
   C. Two integer variables of a and b are declared without values. 
   D. The integer variable a is redefined with a new value 10. From now on, when a is called anywhere, a will be 10.
   E. Same thing above; the integer variable b is redefined with a new value 9. Whenever B is called anywhere, b will be 9.
   F. A new integer variable x is defined. It's definition will be a - b, which is 10 - 9. Whenever x is called anywhere, x will be 1.
   G. Here printf function is called. It prints out the input given. With the string and variable given, it prints out "The outputted number is: 1"
      since it contains both string and the variable x defined beforehand.
   H. Since the main() function was defined as integer, here an integer value of 0 is returned at the end. This indicates that the main function is over



   The output of this function will be "The outputted number is 1". This will be printed out on the console.
   
   
   If a = 10 is replaced to a = "10", this will not yield the same output as a = 10. The program will output a warning, but still
   will be executable. This is because the string "10" has differnet length comapred to the integer 10, so when the program
   calls the variable, the program might get nonsense bytes, which results in a random long number.





5.  Do a modulo operation of 2 to a number and see whether the remainder is 0 or 1. If the remainder is 0, then the number is even, otherwise odd.
    num%2
