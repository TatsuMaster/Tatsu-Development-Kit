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


/******************************************************************************
 *
 * The dirname() function takes a pointer to a character string that contains
 * a pathname, and return a pointer to a string that is a pathname of the
 * parent directory of that file. Trailing ’/’ characters in the path are not
 * counted as part of the path.
 *
 * If path does not contain a ’/’, then dirname() returns a pointer to the
 * string ".". If path is a null pointer or points to an empty string,
 * dirname() returns a pointer to the string ".".
 *
 * The dirname() function need not be thread-safe.
 *
 * The dirname() function returns a pointer to a string that is the parent
 * directory of path. If path is a null pointer or points to an empty string,
 * a pointer to a string "." is returned.
 *
 * The dirname() function may modify the string pointed to by path, and
 * may return a pointer to static storage that may then be overwritten by
 * subsequent calls to dirname().
 *
 *****************************************************************************/
 char *dirname(char *path)
 {
     /* 
      * Tatsu supports up to 65536 bytes for path description, depending on the
      * filesystem used!
      */
     static char dirname[65536];
     static char* zero_base = ".";
     static char* zero_root = "/";

     if (!path)
        return zero_base;

     size_t path_length = strlen(path);

     if (path_length == 0)
        return zero_base;

     if (path_length < 3)
     {
        if (strcmp(path, "/") == 0)
            return zero_root;

        if (strcmp(path, ".") == 0)
            return zero_base;

        if (strcmp(path, "..") == 0)
            return zero_base;
     }

     long index;
     long character_match = -1;
 
     for(index = path_length - 1; index >= 0; --index)
     {
         if (path[index] == '/')
         {
             if (!index)
                return zero_root;

             if(character_match != -1)
             {
                 memset(dirname, 0, 65536);
                 memcpy(dirname, path, 65535 < index ? 65535 : index);
 
                 size_t dirname_length = strlen(dirname);
                 if (dirname[dirname_length - 1] == '/')
                    dirname[dirname_length - 1] = 0;
 
                 return dirname;
             }
         }
         else
         {
            character_match = index;
         }
     }
 
     return zero_base;
 }