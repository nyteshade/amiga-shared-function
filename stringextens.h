#ifndef STRING_EXTENS_H
#define STRING_EXTENS_H

#ifndef __SASC
/**
 * Takes a given string and modifies its contents to all be lowercased. This
 * is a modify in place operation.
 *
 * @param str {char *} the string to convert to lowercase
 * @return {char *} the same pointer but in a modified state
 */
char *strlwr(char *str);

/**
 * Takes a given string and modifies its contents to be in a reversed order.
 * This is a modify in place operation.
 *
 * @param str {char *} the string whose contents should be reversed
 * @return {char *} the same pointer but in a modified state
 */
char *strrev(char *str);
#endif

/**
 * Similar to `strlwr` this function first creates a new copy of the supplied
 * string before passing it in to strlwr to lowercase its contents. Memory is
 * allocated for the new string using AllocVec. The requirements are memory
 * allocation parameters that you might supply to AllocVec. Examples might be
 * `MEMF_CLEAR | MEMF_PUBLIC`.
 *
 * This memory must be freed by the user.
 *
 * @param str {char *} the string to duplicate and lowercase
 * @param requirements {unsigned long} constants that can direct how and where
 * to allocate memory from. See exec/memory.h for more details.
 * @return {char *} a pointer to the newly allocated string, NULL will be
 * returned if the allocation failed.
 */
char *strduplwr(char *str, unsigned long requirements);

/**
 * Similar to `strrev` this function first creates a new copy of the supplied
 * string before passing it in to strrev to reverse its contents. Memory is
 * allocated for the new string using AllocVec. The requirements are memory
 * allocation parameters that you might supply to AllocVec. Examples might be
 * `MEMF_CLEAR | MEMF_PUBLIC`.
 *
 * This memory must be freed by the user.
 *
 * @param str {char *} the string to duplicate and reverse
 * @param requirements {unsigned long} constants that can direct how and where
 * to allocate memory from. See exec/memory.h for more details.
 * @return {char *} a pointer to the newly allocated string, NULL will be
 * returned if the allocation failed.
 */
char *strduprev(char *str, unsigned long requirements);

#endif
