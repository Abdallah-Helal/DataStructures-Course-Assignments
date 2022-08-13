# DataStructures-Course-Assignments

# Problem 1 
## Description:
Different variations of types int and float exist in C++ and other languages. They are usually limited by minimum and maximum values. Sometimes it is desired to have versions of these types with unlimited bounds. Java solves this problem by providing BigInteger and BigDecimal classes. In this problem it is required to develop a new C++ type (class) that can hold unlimited decimal integer values and performs arithmetic operations on them. You will develop in C++ a class, BigInt that supports writing statements with extremely long integer values like these:<br>
<strong>
BigInt num1("123456789012345678901234567890");<br>
BigInt num2("113456789011345678901134567890");<br>
BigInt num3 = num2 + num1;<br> cout << "num1 = " << num1 << endl;<br>
</strong>
 
### Functions:
<ul>
<li>Design the class BigInt that has the following public interface (set of operations available
to use by developers using the class):<br>

<strong> BigInt (string decStr); // Initialize from string and rejects bad input<br>
BigInt (int decInt); // Initialize from integer<br>
BigInt operator+ (BigInt anotherDec);<br>
BigInt operator= (BigInt anotherDec);<br> 
Int size();<br>
</strong>

You will also need to overwrite the << operator as follows:<br> 

<strong>friend ostream& operator << (ostream& out, BigInt b)<br></strong>

Using data encapsulation, you are free to store the digits of the big decimal integer in whatever container you like. You might store them in an array, a vector, a string or whatever. These are details that are not important to the user of your class. You will need to build + and – operations that work on the representation you chose.<br>

<li>Implement the class BigInt and write five test cases (including –ve numbers) to test it.
Implement a program that runs the test cases and verifies the result.
</ul>


# Problem 2 
## Description:
You will develop an application for performing calculations on fractions.

### Functions:
<ul>
<li>First, develop a class Fraction that represents a fraction by one integer divided by 
another, e.g.,1/3 or 3/7.
  <ul>
  <li>This class defines adding, subtracting, multiplying, dividing and comparing (<, >, ==, <=
  and >=) fractions by overloading the standard operators for these operations.

  <li>It should also contain a function for reducing fractions. For example 2/6 is reduced after
  calling the function to 1/3, etc

  <li>You also need to overload I/O operators to be able to input and output fractions
  naturally
  using >> and << operators.

  </ul>

<li>Separate class specifications from implementation by creating Fraction.h for specs and
Fraction.cpp for implementation.

<li>Second, develop a class FractionCalculator that utilizes the class Fraction and allows the user to input a fraction and perform calculations by adding, subtracting, etc. another fraction and then keeping the result as a fraction for further calculations.
</ul>

# Problem 3 
## Description:
   You will develop an application for matrix calculations.

### Functions:
<ul>
 <li>It is required to design and implement a generic class Matrix, in the form of a class template that accepts a type parameter. This way, when the class Matrix is instantiated, we decide if it should accept float, int or double, etc
  
 <li>Matrix class holds a matrix of any size and allocates the required memory as needed.
  
 <li>Matrix class should have a destructor that frees used memory at the end of lifetime of each Matrix objects.
  
 <li>Matrix class specifications should be in a separate header “.h” file. 
 <li>It should have a pointer-to-pointer attribute that points to the matrix content. It should 
havesuitable constructors and methods for allocating the required memory space based on 
the dimensions decided by the user.
  
 <li>Overload standard operators and I/O operators to enable Matrix class with addition, subtraction and multiplication and suitable input and output capabilities. Add a method for matrix transpose.
  
 <li>Then develop a <strong>MatrixCalculator </strong>class which offers the user a menu of operations to perform on int matrices as follows. Each of these options should be able to accept matrices of varying dimensions, which the user inputs. For multiplication, the calculator should check that two matrices are of dimensions n x m and m x p.<br><br>Welcome to (Your Name) Matrix Calculator<hr>
1- Perform Matrix Addition<br>
2- Perform Matrix Subtraction<br>
3- Perform Matrix Multiplication<br>
4- Matrix Transpose<br>
  
</ul>

# Problem 4 
## Description:
   The given function ListPermutations below prints all the permutations of a given string. It is required to modify this function so that it only prints unique strings. The current function will do exhaustive recursion to calculate all permutations. So, if the given string has duplicate characters, the output will have duplicate words. For example, if it is given the string “Makka”, it will print “Mkkaa” four times. Try this function and see how it works.<br>


# Problem 5 
## Description:
### Functions:
<ul>
</ul>

# Problem 6 
## Description:
   Write a program that handles an address book program, to process the following functions
   
### Functions:
<ul>
 <li>First, write a class called PhoneDirectory. Add a first name, last name and phone number entry as a private.
 <li>The main program uses a simple text-based interface to give the user access to the directory. In a while loop, the program presents the user with a menu of options:
  <ol>
   <li>Add an entry to the directory
   <li>Look up a phone number
   <li>Look up a phone number
   <li> Delete an entry from the directory
   <li>List All entries in phone directory
   <li>Exit form this program
  </ol>
 <li>Delete an entry by first name.
 <li>List the directory in alphabetical order by first name.
 <li>Use at least 3 sorting techniques for points 3 & 4, to perform time analysis on these different algorithms.
 <li>Lookup an entry by first name.
 <li>Lookup an entry by phone number.
</ul>

# Problem 7 
## Description:
If you have a list of songs in a music library and want to sort this list alphabetically. However, you want songs with the title “Untitled” to always appear at the top. Write a function called BiasedSort that accepts a vector by reference and sorts the songs according to the explained rules above.


# Problem 8 
## Description:
### Functions:
<ul>
</ul>


# Problem 9 
## Description:
### Functions:
<ul>
</ul>

# Problem 10 
## Description:
### Functions:
<ul>
</ul>
