#include "List.h"
#include "Functions.h"

/*
* ADVANTAGES / DISADVANTAGES LINKED LIST
* One advatage to using a linked list for storing commands and descriptions is that there is no limit to how many commands and descriptions there can be,
* as long as the computer has enought space. 
* One disadvantage though is that you can only access these commands and descriptions linearly, meaning that it would take n time to get to the n'th command
*/

/*
* ADVANTAGES / DISADVANTAGES ARRAY
* One advantage for using an array for the profiles, it's very easily traversable
* One disadvantage for the use of arrayes for the profiles is that we had to place the profile in the front of the array. This causes inputting a new profile to take
* n(the amount of previously stored profiles) operations since we would have to shift all other profiles down.
*/


void main()
{
	srand(time(NULL));
	main_menu();
}