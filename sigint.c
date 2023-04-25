#include "main.h"
/**
 * get_sigint - handle the ctrl + c call promot
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
<<<<<<< HEAD

=======
>>>>>>> 6fc2b98c03a5e6a7cc7328810bac970c903b2eac
}
