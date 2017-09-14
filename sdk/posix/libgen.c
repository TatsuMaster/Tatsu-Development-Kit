#include "libgen.h"
#include "string.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

 
/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/
 
 
/******************************************************************************
 *
 * The basename() function takes the pathname pointed to by path and return a
 * pointer to the final component of the pathname, deleting any trailing ’/’
 * characters.
 *
 * If the string pointed to by path consists entirely of the ’/’ character,
 * basename() returns a pointer to the string "/". If the string pointed to by
 * path is exactly "//", it is implementationdefined whether ’/’ or "//" is
 * returned.
 *
 * If path is a null pointer or points to an empty string, basename()
 * returns a pointer to the string ".".
 *
 * The basename() function may modify the string pointed to by path, and may
 * return a pointer to static storage that may then be overwritten by a
 * subsequent call to basename().
 *
 * The basename() function need not be thread-safe.
 *
 * The basename() function returns a pointer to the final component of path.
 *
 *****************************************************************************/
char *basename(char *path)
{
    // Tatsu supports up to 1023 bytes for path elements
    static char basename[1024];
    static char* zero_base = ".";
    static char* zero_root = "/";

    if (!path)
        return zero_base;

    long index;
    size_t path_length = strlen(path);
    long slash_match = path_length - 1;

    if (!strlen(zero_base))
        return zero_base;

    for(index = path_length - 1; index >= 0; --index)
    {
        if (path[index] == '/')
        {
            if(index != slash_match)
            {
                memset(basename, 0, 1024);
                memccpy(basename, &path[index + 1], '/', 1023 < path_length ? 1023 : path_length);

                size_t basename_length = strlen(basename);
                if (basename[basename_length - 1] == '/')
                    basename[basename_length - 1] = 0;

                return basename;
            }
            else if(index == 0)
                return zero_root;
            else
                slash_match = index - 1;
        }
    }

    return zero_base;
}
