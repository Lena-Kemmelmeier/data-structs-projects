# Homework 3

## Assignment Goals
1.	Continue practice with **linked storage** and **dynamically allocated memory**  
2.	Continue practice using **data structures** to solve problems
3.	Familiarize students with the **stack** ADT

## Problem
Design a system which reads the infix form of a ***single*** arithmetic expression, then outputs the postfix expression and resulting value.  
For example, if the user enters  
```(5 + 6) * (4 / 3)```  

The results should be  
```56+43/*```  
```14.6667```

## Requirements
- Provide a ***complete*** linked implementation for your Stack data structure.   
  - The stack interface has been provided for you in this repository as ```stack.h```
  - The node class has been provided for you in this repository as ```node.h``` and ```node.cpp```
- Save your main program in a file called ```postfix.cpp.```  
- Include a ```makefile``` which produces an executable called ```postfix``` 

You may assume that the infix input expression consists of single-digit, non-negative integers [0 through 9], the four basic arithmetic operators [+ - \* /], and parenthesis [( and )] in the correct order.

## Extra Credit
### Features will **ONLY** be considered for extra credit if the required functionality is *completely* implemented.  
Correct implementation of handling values with more than one digit will earn you an additional 5% of your original points  

## Submission details
To submit your project, you will have to use git on your VirtualBox installation:
1.	After accepting the assignment invitation, copy the clone URL
2.	Type 
```git clone clone URL```
3.	cd into your new assignment directory
4.	After working on your files
5.	When you’re ready, type the following commands: 
```
git add .
git commit -m “your commit message”
git push
```
## Academic Honesty
Academic dishonesty is against university as well as the system community standards. Academic dishonesty includes, but is not limited to, the following:
Plagiarism: defined as submitting the language, ideas, thoughts or work of another as one's own; or assisting in the act of plagiarism by allowing one's work to be used in this fashion.
Cheating: defined as (1) obtaining or providing unauthorized information during an examination through verbal, visual or unauthorized use of books, notes, text and other materials; (2) obtaining or providing information concerning all or part of an examination prior to that examination; (3) taking an examination for another student, or arranging for another person to take an exam in one's place; (4) altering or changing test answers after submittal for grading, grades after grades have been awarded, or other academic records once these are official.
Cheating, plagiarism or otherwise obtaining grades under false pretenses constitute academic
dishonesty according to the code of this university. Academic dishonesty will not be tolerated and
penalties can include cancelling a student’s enrolment without a grade, giving an F for the course, or for the assignment. For more details, see the University of Nevada, Reno General Catalog.
