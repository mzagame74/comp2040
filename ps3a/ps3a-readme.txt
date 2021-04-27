/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Matt Zagame


Hours to complete assignment: 3

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
CircularBuffer emulates a ring buffer feedback mechanism using an array of 
type int16_t which stores n samples of a vibration. The class implements the 
array as a queue to work with the Karplus-Strong algorithm. The CircularBuffer 
constructor and its queue functions include excpetion handling which is 
tested using Boost libraries in test.cpp.



/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
CircularBuffer contains a queue of int16_t data which is modifiable via the
enqueue() and dequeue() functions, which allows data to be added to the end of
the queue and to remove data from the beginning of the queue respectively. 
The class also contains a peek() function for viewing the first element of the
queue without removing anything.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Since the class CircularBuffer dynamically allocates an array of type int16_t,
the rule of the Big 5 applies to the class. Copy/move/destructor, etc included.
enqueue() takes a parameter of type int16_t and appends it to the end of the 
buffer which is at index equal to the size of the buffer, then increments size.
dequeue() holds onto the element at the beginning of the queue and shifts the
entire queue to the left, then decrements size and returns the element.




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I implemented the code as described in the assignment pdf and tested all
the cases that were required to either not throw an exception or to throw an 
exception on purpose.



/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, the boost unit test framework produces zero errors in my terminal when 
running each test case.





/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
The space complexity of the class is O(N) where N is the given capacity of the 
buffer. The time complexity of the class is O(N) when using the function 
dequeue, where N is the current size of the buffer, because it contains a single loop needed to shift each element after removing the first one.




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
