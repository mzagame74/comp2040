/**********************************************************************
 *  readme.txt template                                                   
 *  Markov Model
 **********************************************************************/

Name: Matt Zagame

Hours to complete assignment: ~15 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The Markov Model uses probabilistic analysis on text to determine the next
character(s) in a sequence of k length words called kgrams. The MModel class
takes a string and order k as input and maps each kgram in the string to each
character following that kgram and it's frequency. The class can then generate
a new string given a kgram based on the probability of each next character. The
TextGenerator class uses this string generation function to analyze words in
text files and produce a pseudorandom string of length L that attempts to
recreate the given text.

Example program usage: ./TextGenerator 3 200 < markov/bible.txt


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The MModel class uses a map containing a kgram key and a map of
characters and their frequency as the respective value.
MModel also makes use of the Mersenne Twister random number generator in
the kRand() function.



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
MModel's constructor sets up a map that can be displayed as a table-like output
which holds each kgram and it's frequency, each next character and it's
frequency as well as probability. The function generate() uses kRand() as a
helper function, which selects a random next character from a kgram string when
building a new string out of previously generated characters.




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, although TextGenerator is not perfect as it sometimes does not work with
certain text files and their spacings.



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, the Boost unit tests run properly.



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
Exceptions are present in the MModel constructor and functions, and
TextGenerator is responsbile for catching and handling these exceptions.




 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

