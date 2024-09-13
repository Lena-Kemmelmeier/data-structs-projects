# Homework 2

## Project Goals
The goal of this project is to:
1.	Familiarize students with **linked lists**
2.  Familiarize students with **array storage** and **linked storage**.
3.  Practice **time complexity** analysis.

## Program
Add functionality for the incomplete data structure functions.  

Modify this README document with a paragraph (at least three complete sentences) explaining why the different storage methods are better for the different lists used in the driver.
# EXPLANATION GOES UNDER HERE 
We implemented a linked-based 'to-do' list and an array-based 'done' list. For this project, our 'to-do' list needs to both insert and remove items easily. It is better to use a linked-based list rather than an array-based list for storing the 'to-do' items because we do not need to shift data items, only rearrange pointers. For our 'done' list, on the other hand, the user is not interested in removing items, only adding, which is why having to shift data around is a bit less of a concern. With an array list, we can directly access items in the list in costant time. Besides letting the user add items to our 'done' list, we also want to let the user display all the items currently in the list. The benefit of using an array-based implementation here is that we don't ever have to traverse through the list when getEntry() is called in  displayList() like we would have to do with a linked-list, which avoids a linear time complexity issue (especially apparent if there were a lot of nodes in the chain). I would argue that for the linked 'to-do' list, the ease in removing/inserting items outweighs its time complexity disadvantage in this particular case.   

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
