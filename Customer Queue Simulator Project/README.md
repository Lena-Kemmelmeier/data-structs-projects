# Homework 4

## Assignment Goals
1.	Continue practice with **array storage**  
2.	Continue practice using **data structures** to solve problems
3.	Familiarize students with the **queue** ADT

## Problem
Implement the event-driven simulation of a bank mentioned in the textbook (Question 6). A queue of arrival events will represent the line of customers in the bank. Maintain the arrival events and departure events in a priority queue, sorted by the time of the event. 

The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. The arrival times are ordered by increasing time.

Your program must count customers and keep track of their cumulative waiting time. These statistics are sufficient to compute the average waiting time after the last event has been processed. Display a trace of the events executed and a summary of the computed statistics (the total number of arrivals and average time spent waiting in line). For example, the input file shown in below should produce the output shown at the bottom of the assignment.

### There is a "HelpfulFiles" folder in this repository with
- an example Design Document
- Questions 6 & 7 from the textbook
- a break down of an approach to solving the problem (from the textbook)

## Requirements
- Provide a ***complete*** array implementation for your Queue data structure.   
  - The queue interface has been provided for you in this repository as ```queue.h```
- Include a ```makefile``` which produces an executable called ```bank_sim```
- There is an ```input.txt``` file in this repository which the autograder will use to test your code.
  - This will not determine your grade, ***it is for your testing purposes only***.  

## Extra Credit
### Features will **ONLY** be considered for extra credit if the required functionality is *completely* implemented.  
Correct implementation of Question 7 in the textbook will earn you an additional 5% of your original points   

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
