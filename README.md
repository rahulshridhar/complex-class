# complex-class
Implementing a class that stores real (x) and imaginary (y) numbers along with string (x + iy).

Create a class called complex that has 
1. Real number, x
2. Imaginary number, y
3. construct a name x+iy on heap and store the pointer. (YOU CANNOT USE STL string)

You should be able to construct complex objects using 3 ways
complex h ; //In that case x = 0, y = 0
complex h(5) ; //In that case x = 5, y = 0 ;
complex h(5,-8) ; //In that case x = 5 and y = -8

Steps to run the program:-
1. cd complex
2. g++ -std=c++11 complex.cpp complextest.cpp -o complex
3. ./complex
