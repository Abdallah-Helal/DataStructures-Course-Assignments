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
<ol>
<li>Design the class BigInt that has the following public interface (set of operations available
to use by developers using the class)<br>
<strong> BigInt (string decStr); // Initialize from string and rejects bad input<br>
BigInt (int decInt); // Initialize from integer<br>
BigInt operator+ (BigInt anotherDec);<br>
BigInt operator= (BigInt anotherDec);<br> 
Int size();<br>
</strong>
You will also need to overwrite the << operator as follows:<br> 
<strong>friend ostream& operator << (ostream& out, BigInt b)<br></strong>

Using data encapsulation, you are free to store the digits of the big decimal integer in whatever container you like. You might store them in an array, a vector, a string or whatever. These are details that are not important to the user of your class. You will need to build + and – operations that work on the representation you chose.<br>

- Implement the class BigInt and write five test cases (including –ve numbers) to test it.
Implement a program that runs the test cases and verifies the result.
