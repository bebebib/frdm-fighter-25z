// syscalls.c

// This is just a bunch of stdlib stubs so we can use the debug console in printf!

#include <stdio.h>
#include <errno.h>

// Stubs we do not care about.. for now!
void _exit (void)
{}

void _kill (void)
{}

void _getpid (void)
{}

// From  newlib https://github.com/eblot/newlib/blob/master/libgloss/epiphany/sbrk.c
// This is needed for printf
void *
_sbrk (int  incr)
{
	extern char _pvHeapStart;//set by linker
	extern char _pvHeapLimit;//set by linker

	static char *heap_end;		/* Previous end of heap or 0 if none */
	char        *prev_heap_end;

	if (0 == heap_end) {
		heap_end = &_pvHeapStart;			/* Initialize first time round */
	}

	prev_heap_end  = heap_end;
	heap_end      += incr;
	//check
	if( heap_end < (&_pvHeapLimit)) {

	} else {
		errno = ENOMEM;
		return (char*)-1;
	}
	return (void *) prev_heap_end;

}	/* _sbrk () */

void _close (void)
{}

void _fstat (void)
{}

void _isatty (void)
{}

void _lseek (void)
{}