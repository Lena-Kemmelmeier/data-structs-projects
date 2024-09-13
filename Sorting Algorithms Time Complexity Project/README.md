# Homework 5

## Assignment Goals
The goal of this project is to:
1.	Familiarize students with **sorting**
2.  Apply **time complexity** analysis.

## Problem
Let's measure the performance of different sorting algorithms!

## Requirements
### Overview
- generate 3 sets of random numbers, each a different size
- implement three sorting algorithms
  - use them to sort the random numbers
  - use them to sort the sorted numbers
  - save measurements of 3 metrics
- use the measurements to create graphs

### Number Sets
Your program should generate 3 sets of random integer values in the range of 0 to 1,000,000. Each set of random numbers should be a different size:
1. 1,000
2. 10,000
3. 100,000.

This will help us analyze the performance of the algorithms as the size of the problem grows.  

You'll also need to save a sorted copy of each sized set (it's fine if you generate this by running one of your sorts over the original random sets). This will help highlight which sorts actually perform worse on data that's already sorted!  

Altogether, there are 6 sets of numbers to go through our sorting algorithms: 3 sizes and 2 categories (sorted or unsorted).

### Sorting Algorithm
Your program should implement three sorting algorithms. TWO of the algorithms should be from the following list:
- selection sort
-	insertion sort
-	bubble sort  

ONE algorithm should be from the following list:
-	merge sort
-	quick sort 

### Data Analysis
#### Raw Measurements - save the metric measurements to one or more files:
- each sorting algorithms should sort each set of numbers (unsorted and sorted) 10 times
  - that's a total of 20 runs per algorithm and data size
- the following metric measurements should be saved each time the algorithm is run over a data set
  -	the CPU time (use the same machine)
  -	the number of comparisons
  -	the number of swaps  
-	see the example data files for an example

#### Graphs - create graphs to compare each algorithm's metric as the size of the data grows:
- There should be a graph for every metric and category of data
  -	use the ***average*** of the 10 runs for each algorithm, data size, category, measurement
  -	each graph has 3 lines
-	for example, **CPU Time** for the **Unsorted** data
    -	the X-axis: each algorithm's average measurement for the metric
    -	the Y-axis: data size 
-	see the example data files for an example
     
### Deliverables
-	Source code for any classes you include
-	A *modular* main driver
-	a makefile
- 180 raw measurement values in one or more files
  - A combination of
    - 3 sorting algorithms
    - 10 runs to get the average
    - 3 metric measurements per run
    - 3 sizes
    - 2 categories (sorted or unsorted)
  - A .csv file is just a "comma separated" file
    - If you use that file extension and a comma between the data when saving the data from your program, it will automagically have rows and columns when you open it with Excel
- 6 Graphs in one or more files
  - It's easy to convert .csv files to .xlsx files in Excel just by using the "Save As" option

Please see the example output files in this repository for more information.  
### Helpful Resources
- Measuring execution timing
  - https://www.geeksforgeeks.org/measure-execution-time-function-cpp
- Generating random numbers
  - https://www.bitdegree.org/learn/random-number-generator-cpp
  - https://en.cppreference.com/w/cpp/numeric/random/rand

## Extra Credit
### Features will **ONLY** be considered for extra credit if the required functionality is *completely* implemented.  
You may implement all 5 algorithms for extra credit up to 5% (2.5% for each sort). To receive extra credit for this work, indicate which are your 3 main algorithms and which 2 are extra credit. The 3 main algorithms must receive full credit for your 2 extra credit algorithms to be considered for credit.

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
