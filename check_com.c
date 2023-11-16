#include "main.h"

/**
* checker - checks program in interactive modde
*
* Return: 1 interactive mode or 0 otherwise
*/
int checker(void)
{
	return (isatty(STDIN_FILENO));
}
