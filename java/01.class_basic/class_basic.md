# Basic of Class
## Question
1. How to use another class?
2. How to protect class field?
3. How to use constructor?
4. How to divide java source files and integrate with compile?
5. Is it possible to compile another java file in different path?

## Answer
1. like c++
2. write access modifier before field
3. like c++
4. Just divide class to another file and then compile main java file
  * Exam1_3.java (main)
  * Dog.java
  * java Exam1_3.java
5. Read and follow below sentences
  * make cat directory
  * create cat.java
  * It should have public class and public concstructor and public method
  * Write at first line to "package exampkg" at Exam1_3.java file. 
  * Write at first line to "package animal" at Cat.java file. 
  * Write to "import animal.*" at second line at Exam1_3.java file. 
  * java -d . Exam1_3.java

## Reference Source File
* Q1, Q2, Q3 => Exam1_2.java
* Q4, Q5 : Exam1_3.java
