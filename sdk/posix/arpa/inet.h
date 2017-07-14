#ifndef ARPA_INET_H
#define ARPA_INET_H


#ifdef __x86_64__
#else
#define HOST_BIG_ENDIAN
#endif

#ifdef HOST_BIG_ENDIAN
#define htons(value) value
#define htonl(value) value
#define htonll(value) value

#define ntohs(value) value
#define ntohl(value) value
#define ntohll(value) value
#else
#define htons(value) SWAP16(value)
#define htonl(value) SWAP32(value)
#define htonll(value) SWAP64(value)

#define ntohs(value) SWAP16(value)
#define ntohl(value) SWAP32(value)
#define ntohll(value) SWAP64(value)

#define SWAP16(val) ((((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00))

#define SWAP32(val) ((((val) >> 24) & 0x000000FF) | (((val) >>  8) & 0x0000FF00) | \
                    (((val) <<  8) & 0x00FF0000) | (((val) << 24) & 0xFF000000) )

#define SWAP64(val) ((((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | \
                    (((val) >> 24) & 0x0000000000FF0000) | (((val) >>  8) & 0x00000000FF000000) | \
                    (((val) <<  8) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | \
                    (((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000) )
#endif

#endif
