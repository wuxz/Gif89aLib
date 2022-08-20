/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Sat Jun 13 22:52:55 1998
 */
/* Compiler settings for Gif89.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IGif89a = {0x28D4752F,0xCF84,0x11D1,{0x83,0x4C,0x00,0xA0,0x24,0x9F,0x0C,0x28}};


const IID LIBID_GIF89Lib = {0x28D47522,0xCF84,0x11D1,{0x83,0x4C,0x00,0xA0,0x24,0x9F,0x0C,0x28}};


const CLSID CLSID_Gif89a = {0x28D47530,0xCF84,0x11D1,{0x83,0x4C,0x00,0xA0,0x24,0x9F,0x0C,0x28}};


#ifdef __cplusplus
}
#endif

