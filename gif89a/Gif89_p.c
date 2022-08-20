/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.01.75 */
/* at Sat Jun 13 22:52:55 1998
 */
/* Compiler settings for Gif89.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY

#include "rpcproxy.h"
#include "Gif89.h"

#define TYPE_FORMAT_STRING_SIZE   61                                
#define PROC_FORMAT_STRING_SIZE   415                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IGif89a, ver. 0.0,
   GUID={0x28D4752F,0xCF84,0x11D1,{0x83,0x4C,0x00,0xA0,0x24,0x9F,0x0C,0x28}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGif89a_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x301004b, /* MIDL Version 3.1.75 */
    0,
    UserMarshalRoutines,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IGif89a_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    24,
    48,
    72,
    90,
    108,
    132,
    156,
    180,
    204,
    228,
    252,
    276,
    300,
    324,
    348,
    372,
    396
    };

static const MIDL_SERVER_INFO IGif89a_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IGif89a_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IGif89a_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IGif89a_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(25) _IGif89aProxyVtbl = 
{
    &IGif89a_ProxyInfo,
    &IID_IGif89a,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IGif89a::put_Enabled */ ,
    (void *)-1 /* IGif89a::get_Enabled */ ,
    (void *)-1 /* IGif89a::get_Window */ ,
    (void *)-1 /* IGif89a::Play */ ,
    (void *)-1 /* IGif89a::Stop */ ,
    (void *)-1 /* IGif89a::get_AutoStart */ ,
    (void *)-1 /* IGif89a::put_AutoStart */ ,
    (void *)-1 /* IGif89a::get_Speed */ ,
    (void *)-1 /* IGif89a::put_Speed */ ,
    (void *)-1 /* IGif89a::get_Glass */ ,
    (void *)-1 /* IGif89a::put_Glass */ ,
    (void *)-1 /* IGif89a::put_AutoSize */ ,
    (void *)-1 /* IGif89a::get_AutoSize */ ,
    (void *)-1 /* IGif89a::get_Embed */ ,
    (void *)-1 /* IGif89a::put_Embed */ ,
    (void *)-1 /* IGif89a::get_FileName */ ,
    (void *)-1 /* IGif89a::put_FileName */ ,
    (void *)-1 /* IGif89a::AboutBox */
};


static const PRPC_STUB_FUNCTION IGif89a_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGif89aStubVtbl =
{
    &IID_IGif89a,
    &IGif89a_ServerInfo,
    25,
    &IGif89a_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure put_Enabled */

			0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/*  2 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  4 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/*  6 */	NdrFcShort( 0x6 ),	/* 6 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter vbool */

/* 12 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 14 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 16 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 18 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 20 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 22 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Enabled */

/* 24 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 28 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0xe ),	/* 14 */
/* 34 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pbool */

/* 36 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 38 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 40 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 42 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 44 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 46 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Window */

/* 48 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 50 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x10 ),	/* 16 */
/* 58 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter phwnd */

/* 60 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 62 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Play */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 74 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 76 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */

/* 84 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 86 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 88 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */

/* 90 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 92 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 94 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x8 ),	/* 8 */
/* 100 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 104 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AutoStart */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 110 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 112 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 116 */	NdrFcShort( 0xe ),	/* 14 */
/* 118 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 120 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 122 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 124 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 128 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AutoStart */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 134 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 138 */	NdrFcShort( 0x6 ),	/* 6 */
/* 140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 142 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 144 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 146 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 148 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 150 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 152 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Speed */

/* 156 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 158 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 160 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 166 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 168 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 170 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 176 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Speed */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 182 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 184 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 190 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 192 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 194 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 200 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Glass */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 206 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 208 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0xe ),	/* 14 */
/* 214 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 216 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 218 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 220 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 224 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Glass */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 230 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 232 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 234 */	NdrFcShort( 0x6 ),	/* 6 */
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 240 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 242 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 244 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 248 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AutoSize */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 254 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 256 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 258 */	NdrFcShort( 0x6 ),	/* 6 */
/* 260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 262 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter vbool */

/* 264 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 266 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 268 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 272 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AutoSize */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 278 */	NdrFcShort( 0x13 ),	/* 19 */
#ifndef _ALPHA_
/* 280 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0xe ),	/* 14 */
/* 286 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pbool */

/* 288 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 290 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 292 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 296 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Embed */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 302 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
/* 304 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0xe ),	/* 14 */
/* 310 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 312 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 314 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 316 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 320 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Embed */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 326 */	NdrFcShort( 0x15 ),	/* 21 */
#ifndef _ALPHA_
/* 328 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 330 */	NdrFcShort( 0x6 ),	/* 6 */
/* 332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 334 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 336 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 338 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 340 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 344 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FileName */

/* 348 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 350 */	NdrFcShort( 0x16 ),	/* 22 */
#ifndef _ALPHA_
/* 352 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 358 */	0x5,		/* 5 */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 360 */	NdrFcShort( 0x2113 ),	/* 8467 */
#ifndef _ALPHA_
/* 362 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 364 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 368 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FileName */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 374 */	NdrFcShort( 0x17 ),	/* 23 */
#ifndef _ALPHA_
/* 376 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 382 */	0x6,		/* 6 */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 384 */	NdrFcShort( 0x8b ),	/* 139 */
#ifndef _ALPHA_
/* 386 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 388 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 392 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AboutBox */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 398 */	NdrFcShort( 0x18 ),	/* 24 */
#ifndef _ALPHA_
/* 400 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 406 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 410 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  2 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/*  4 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  6 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  8 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 10 */	NdrFcShort( 0x1a ),	/* Offset= 26 (36) */
/* 12 */	
			0x13, 0x0,	/* FC_OP */
/* 14 */	NdrFcShort( 0xc ),	/* Offset= 12 (26) */
/* 16 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 18 */	NdrFcShort( 0x2 ),	/* 2 */
/* 20 */	0x9,		/* 9 */
			0x0,		/*  */
/* 22 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 24 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 26 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
/* 30 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (16) */
/* 32 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 34 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 36 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (12) */
/* 46 */	
			0x12, 0x0,	/* FC_UP */
/* 48 */	NdrFcShort( 0xffffffea ),	/* Offset= -22 (26) */
/* 50 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x4 ),	/* 4 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (46) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _Gif89_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IGif89aProxyVtbl,
    0
};

const CInterfaceStubVtbl * _Gif89_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IGif89aStubVtbl,
    0
};

PCInterfaceName const _Gif89_InterfaceNamesList[] = 
{
    "IGif89a",
    0
};

const IID *  _Gif89_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _Gif89_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Gif89, pIID, n)

int __stdcall _Gif89_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_Gif89_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo Gif89_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Gif89_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Gif89_StubVtblList,
    (const PCInterfaceName * ) & _Gif89_InterfaceNamesList,
    (const IID ** ) & _Gif89_BaseIIDList,
    & _Gif89_IID_Lookup, 
    1,
    2
};
