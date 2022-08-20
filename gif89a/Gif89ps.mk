
Gif89ps.dll: dlldata.obj Gif89_p.obj Gif89_i.obj
	link /dll /out:Gif89ps.dll /def:Gif89ps.def /entry:DllMain dlldata.obj Gif89_p.obj Gif89_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del Gif89ps.dll
	@del Gif89ps.lib
	@del Gif89ps.exp
	@del dlldata.obj
	@del Gif89_p.obj
	@del Gif89_i.obj
