#ifndef GET_SHELL_WIN_H
#define GET_SHELL_WIN_H

#include <exec/memory.h>
#include <libraries/dos.h>
#include <libraries/dosextens.h>
#include <intuition/intuition.h>
#include <devices/conunit.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>

/**
 * The three variables required to fetch the shell window. They are wrapped
 * in this structure when invoked and discarded unless `GetShellWindowContext`
 * is invoked.
 */
typedef struct GSHContext {
  struct Window *window;
	struct IORequest *ior;
	struct ConUnit *conUnit;
} GSHContext;

/**
 GetShellWindow() is a function that will attempt to get a handle on the
 CLI/Shell window that it is executed from. If none can be found, then
 NULL will be returned.
 
 @returns {struct Window} a pointer to a Window struct for this window or
 NULL if one could not be located.
 */
struct Window *GetShellWindow(void);

/**
 In order to fetch the current CLI/Shell window, an IORequest and ConUnit
 are exposed. This function returns the additional context required to
 fetch the window itself.
 
 On error, the contents of the returned struct will be NULL values.
 
 @returns {GSHContext} an struct containing the Window, IORequest and ConUnit
 */
GSHContext GetShellWindowContext(void);

#endif