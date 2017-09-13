#include "unistd.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

typedef union
{
    unsigned short value;
    char byte_sequence[2];
} swab_storage;


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/******************************************************************************
 *
 * The swab() function shall copies nbytes bytes, which are pointed to by src,
 * to the object pointed to by dest, exchanging adjacent bytes. The nbytes
 * argument should be even. If nbytes is odd, swab() copies and exchanges
 * nbytes−1 bytes and the disposition of the last byte is unspecified. If
 * copying takes place between objects that overlap, the behavior is undefined.
 * If nbytes is negative, swab() does nothing.
 *
 *****************************************************************************/
void swab(const void *__restrict__ src, void *__restrict__ dest, ssize_t nbytes)
{
    if (nbytes < 0)
        return;

    if ((nbytes % 2) == 1)
        --nbytes;

    if (nbytes == 0)
        return;

    ssize_t index;
    unsigned short* _src = (unsigned short*)src;
    unsigned short* _dest = (unsigned short*)dest;
    nbytes /= 2;

    for(index = 0; index < nbytes; ++index)
    {
        swab_storage tmp;
        char byte;

        tmp.value = _src[index];
        byte = tmp.byte_sequence[0];

        tmp.byte_sequence[0] = tmp.byte_sequence[1];
        tmp.byte_sequence[1] = byte;

        _dest[index] = tmp.value;
    }
}
