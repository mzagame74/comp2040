/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Matt Zagame


Hours to complete assignment: ~8 hours


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I completed the assignment successfully.


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
The only regex I used was for capturing the date and time reported on each boot
started line or boot completed line. The actual boot messages were constant and
could be scanned without the use of regex.

regex: "^\\d{4}[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])\\s\\d{2}[:]\\d{2}
[:]\\d{2}"


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
The program reads a log file line by line and determines whether a boot has
started or completed depending on the message scanned. If it contains a boot
start message then the date and time is saved and reported. Once a boot
completed message is scanned, the date and time is saved again along with the
total boot time from start to completion. This information is saved to a report
file (.rpt) containing each successful and unsuccessful boot.



/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
No




/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/


