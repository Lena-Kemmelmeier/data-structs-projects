# Homework 1

## Project Goals
The goal of this project is to:
1.	Review **C++**
2.  Review **Templates**
3.  Review **Interfaces**
4.  Review **Operator Overloading**
5.  Review **makefiles**

## Program
Moving and shaking! We're going to create a program that moves trains carrying cargo and buses carrying people. 

Trains and buses are "transporters". Any transporter MUST be able to be **load**ed with one item, **unload**ed with one item, **empty**-ed of all items, **move**d. They must also be able to report back whether or not they **are empty** and **how many items** they are carrying.  

Additionally while a train and a bus **must** be able to store items of any type, in this project a train should store *cargo* and a bus should transport *people*. When cargo is loaded onto a train, it doesn't matter where it goes but people on the bus should "sit" from shortest to tallest. Also, a train must be able to report on the weight of all its cargo and a bus must be able to change its fare and give the total fair for all the people on the bus. When a train moves, it can display that it's reached the next destination. When a bus moves, it can display that it's reached the next stop.

Finally, each cargo must have a type and a weight and each person must have a name and a height.

The main driver of your program must create a train and load it with some cargo. It must also create a bus and let people board. It must also demonstrate the rest of the required functionality as specified.  

All console input and output should occur in the main function (except for what's displayed in the move functions).  

## **A MAKEFILE IS REQUIRED**

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
