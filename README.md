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
### Functions:
<ul>
</ul>

# Problem 4 
## Description:
### Functions:
<ul>
</ul>

# Problem 5 
## Description:
### Functions:
<ul>
</ul>

# Problem 6 
## Description:
### Functions:
<ul>
</ul>

# Problem 7 
## Description:
### Functions:
<ul>
</ul>

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
