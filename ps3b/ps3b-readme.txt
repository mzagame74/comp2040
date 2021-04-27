/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Matt Zagame

Hours to complete assignment : ~10

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, the program works as intended. The correct sounds are played when the 
corresponding keys are pressed.


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 **********************************************************************/
No, I did not have time to work on the extra credit.

/**********************************************************************
 *  Did you implement exceptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
The StringSound(frequency) constructor has one exception that prevents 
construction with a frequency of 0. StringSound handles exceptions thrown by 
CircularBuffer when dynamically allocating memory for the buffer during 
construction and when using the CircularBuffer functions in its own functions.


/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
