Title- Calculator
Name- Shrikrushna D. Kulkarni
MIS- 111308040
--------------------------------------------------------------------------



For simplicty of writing and compiling entire code is 
divided into multiple files.
File cal.h is the header file that includes all function definations
main.c contains a small code .It simply calls required functions like inirialising curses
drawcal function etc.
Functions.c and trigfuns.c are main code files.
trigfuns.c contains all scientific functions like sine,cos  etc
Functions.c contains numeric calculation code and code to move curser and all other graphics 
functions.




I tried to address is to make a simple calculator.
The conventional calculator programs in c are command line base and does not have graphical interface.
To make it more "User friendly" graphical interface was needed to be added.
For this new library ncurses was included in program.
The major problems were:
				 moving cursor on the screen at proper places
				 Taking input from the screen
				 Display outputs properly
				 clear screen at proper times
				 In infix calculation storing inputs properly in a string and then separating it
				 in diffrent strings
