/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Matt Zagame
Hours to complete assignment: 5
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The Linear Feedback Shift Register stores a sequence of bits which are
shifted to the left and uses tap bits to acquire the rightmost bit. 
I used a dynamic array of integers to store the supplied seed (input bits)
and to perform steps by assigning each bit starting on the left to its 
corresponding bit to the right. I made sure to test that both the step()
and generate() functions produced the expected output and I also tested an
exception case where a supplied seed was shorter/longer than the required
16 bits for the register.



/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
None

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No problems

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
