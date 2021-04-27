/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Matt Zagame

Hours to complete assignment: ~7 hours

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg�s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
My edit distance algorithm uses the dynamic programming approach of filling up
a matrix from bottom right to top left in order to get the optimal distance at
position [0][0]. The alignment path is also displayed by tracing the matrix in
reverse order from top left to bottom right. The dynamic programming approach
allows for the calcuations of the alingment to be broken up into subproblems
and then stored, instead of calculating the same subproblem several times.


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: ./ED < sequence/endgaps7.txt

Expected output: 
Edit distance = 4
a — 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
— a 2

What happened:
Edit distance = 4
a — 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
— a 2



/**********************************************************************
 * Look at your computer�s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
My virtual machine has 4GB of RAM. RAM is the available system memory that
can hold the data allocated by my program during runtime. For example, the
matrix of vectors in ED uses RAM during program runtime.


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4 bytes per int (from vector<int>)
b = 2 (traversing the matrix uses a nested loop)
largest N = sqrt(2000000000) ~= 44721

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you�re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
Yes, when using the two strings from ecoli10000.txt, we get a reported usage of 
382.2MB which is slightly under the expected 4*10000^2 = 400MB.


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118             0.054474            24.11  
ecoli5000.txt       160             0.19789             95.89
ecoli7000.txt       194             0.371664            187.4
ecoli10000.txt      223             0.713206            382.2
ecoli20000.txt      3135            3.02736             1491
ecoli28284.txt      8394            13.0928             2982

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4 bytes
b = 3.83 (average of ratios of runtimes at N to runtimes at 2N)
largest N = 2560000 (largest doubling of N under 86400 seconds (1 day))

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
No



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
CPU: Intel Core i7
CPU Speed: 2590 MHz
Memory: 3.9GB
OS: Ubuntu 18.04.5 LTS