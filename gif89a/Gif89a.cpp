// Gif89a.cpp : Implementation of CGif89a
#include "stdafx.h"
#include "Gif89.h"
#include "Gif89a.h"
#include<stdio.h>
DWORD WINAPI ThreadFunc(CGif89a* ptr);
BOOL CALLBACK DialogProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam); 
/////////////////////////////////////////////////////////////////////////////
// CGif89a


HRESULT CGif89a::OnDraw(ATL_DRAWINFO& di)
{
	GetAmbientUserMode(m_bRunMode);
	if(!m_bRunMode)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		OLE_COLOR backcolor;
		COLORREF cl;
		HBRUSH br;
		HBITMAP bmp,oldbitmap;
		if(m_bGlass==FALSE)
		{
			HPALETTE pal;
			GetAmbientPalette(pal);
			GetAmbientBackColor(backcolor);
			OleTranslateColor(backcolor,pal,&cl);
			br=CreateSolidBrush(cl);
			FillRect(di.hdcDraw,&rc,br);
			DeleteObject(br);
		}
		m_hDC=di.hdcDraw;
		bmp=FirstImage();
		if(bmp!=0)
		{
			HDC dc;
			dc=CreateCompatibleDC(di.hdcDraw);
			oldbitmap=(HBITMAP)SelectObject(dc,bmp);
			::BitBlt(di.hdcDraw,rc.left+m_iLeft,rc.top+m_iTop,m_iWidth,m_iHeight,dc,0,0,SRCCOPY);
			SelectObject(dc,oldbitmap);
			DeleteObject(bmp);
			DeleteDC(dc);
		}
		else
		{
			DrawText(di.hdcDraw, _T("Gif Control"), -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		m_pcGifTrack=m_pcGif;
		m_iTotalReadByte=0;
	}
	else
	{
		if((flag==0)&&(m_bAutoStart!=FALSE))
		{
			flag=1;
			OLE_COLOR backcolor;
			RECT& rc = *(RECT*)di.prcBounds;
			HBRUSH br;
			COLORREF cl;
			if(m_bGlass==FALSE)
			{
				HPALETTE pal;
				GetAmbientPalette(pal);
				GetAmbientBackColor(backcolor);
				OleTranslateColor(backcolor,pal,&cl);
				br=CreateSolidBrush(cl);
				FillRect(di.hdcDraw,&rc,br);
				DeleteObject(br);
			}
			Play();
			return S_OK;
		}
		if((flag==0)&&(m_bAutoStart==FALSE))
		{
			OLE_COLOR backcolor;
			HBRUSH br;
			COLORREF cl;
			if(m_bGlass==FALSE)
			{
				RECT& rc = *(RECT*)di.prcBounds;
				HPALETTE pal;
				GetAmbientPalette(pal);
				GetAmbientBackColor(backcolor);
				OleTranslateColor(backcolor,pal,&cl);
				br=CreateSolidBrush(cl);
				FillRect(di.hdcDraw,&rc,br);
				DeleteObject(br);
			}
			return S_OK;
		}

		if(m_hRedrawBitmap!=0)
		{
			while(m_bLockBitmap);
			m_bLockBitmap=TRUE;
			HBITMAP old;
			HBRUSH br;
			OLE_COLOR backcolor;
			RECT& rc = *(RECT*)di.prcBounds;
			COLORREF cl;
			if(m_bGlass==FALSE)
			{
				HPALETTE pal;
				GetAmbientPalette(pal);
				GetAmbientBackColor(backcolor);
				OleTranslateColor(backcolor,pal,&cl);
				br=CreateSolidBrush(cl);
				FillRect(di.hdcDraw,&rc,br);
				DeleteObject(br);
			}
			HDC dc=::CreateCompatibleDC(di.hdcDraw);
			old=(HBITMAP)::SelectObject(dc,m_hRedrawBitmap);
			::BitBlt(di.hdcDraw,0,0,m_iGifWidth,m_iGifHeight,dc,0,0,SRCCOPY);
			::SelectObject(dc,old);
			m_bLockBitmap=FALSE;
			DeleteDC(dc);
		}
	}
	return S_OK;
}

STDMETHODIMP CGif89a::AboutBox()
{

	DialogBox(_Module.m_hInst,MAKEINTRESOURCE(IDD_DIALOGBAR),0,DialogProc);
	return S_OK;
}

STDMETHODIMP CGif89a::Play()
{
	// TODO: Add your implementation code here
	HANDLE hThread;
	DWORD ThreadId;
	if(m_hWnd==0)return S_OK;
	if(m_pcGif==0)return S_OK;
	if(m_EndRun==5)return S_OK;
	m_pcGifTrack=m_pcGif;
	m_iTotalReadByte=0;
	m_EndRun=5;
	hThread=CreateThread(NULL,0,(unsigned long(_stdcall*)(void*))ThreadFunc,this,0,&ThreadId);
	CloseHandle(hThread);
	return S_OK;
}

STDMETHODIMP CGif89a::Stop()
{
	// TODO: Add your implementation code here
	if(m_EndRun!=5)return S_OK;
	m_EndRun=1;
	while(m_EndRun!=2);
	return S_OK;
}

STDMETHODIMP CGif89a::get_FileName(BSTR * pVal)
{
	// TODO: Add your implementation code here
	USES_CONVERSION;
	*pVal=T2BSTR(filename);
	return S_OK;
}

STDMETHODIMP CGif89a::put_FileName(BSTR newVal)
{
	// TODO: Add your implementation code here
	USES_CONVERSION;
	strcpy(filename,OLE2T(newVal));	
	if(!Load(filename)){FireViewChange();return S_OK;}
	if(m_bAutoStart)flag=0;
	if(m_bAutoSize1)
	{
		SIZEL size5,size6;
		size5.cx=m_iGifWidth;
		size5.cy=m_iGifHeight;
		AtlPixelToHiMetric(&size5,&size6);
		m_rcPos.right=m_iGifWidth+m_rcPos.left;
		m_rcPos.bottom=m_iGifHeight+m_rcPos.top;
		SetExtent(DVASPECT_CONTENT,&size6);
		if((m_spInPlaceSite!=NULL)&&m_bInPlaceActive)m_spInPlaceSite->OnPosRectChange(&m_rcPos);
		else if(m_hWnd!=NULL)SetWindowPos(NULL,m_rcPos.left,m_rcPos.top,m_iGifWidth,m_iGifHeight,SWP_NOZORDER|SWP_NOMOVE|SWP_NOACTIVATE);
	}
//	FireViewChange();
	return S_OK;
}

STDMETHODIMP CGif89a::get_AutoStart(VARIANT_BOOL * pVal)
{
	// TODO: Add your implementation code here
	*pVal=m_bAutoStart;
	return S_OK;
}

STDMETHODIMP CGif89a::get_AutoSize(VARIANT_BOOL * pVal)
{
	// TODO: Add your implementation code here
	*pVal=m_bAutoSize1;
	return S_OK;
}

STDMETHODIMP CGif89a::put_AutoStart(VARIANT_BOOL newVal)
{
	// TODO: Add your implementation code here
	m_bAutoStart=newVal;
	m_bRequiresSave=TRUE;
	return S_OK;
}

STDMETHODIMP CGif89a::put_AutoSize(VARIANT_BOOL newVal)
{
	// TODO: Add your implementation code here
	if((newVal)&&(m_pcGif!=0))
	{
		SIZEL size5,size6;
		size5.cx=m_iGifWidth;
		size5.cy=m_iGifHeight;
		m_rcPos.right=m_iGifWidth+m_rcPos.left;
		m_rcPos.bottom=m_iGifHeight+m_rcPos.top;
		AtlPixelToHiMetric(&size5,&size6);
		SetExtent(DVASPECT_CONTENT,&size6);
		if((m_spInPlaceSite!=NULL)&&m_bInPlaceActive)m_spInPlaceSite->OnPosRectChange(&m_rcPos);
		else if(m_hWnd!=NULL)SetWindowPos(NULL,m_rcPos.left,m_rcPos.top,m_iGifWidth,m_iGifHeight,SWP_NOZORDER|SWP_NOMOVE|SWP_NOACTIVATE);
		FireViewChange();
	}
	m_bRequiresSave=TRUE;
	m_bAutoSize1=newVal;
	return S_OK;
}

CGif89a::CGif89a()
{
	m_bAutoStart=TRUE;
	m_bAutoSize1=TRUE;
	m_bEmbed=FALSE;
	m_pcGlobalColorTable=0;
	m_pcGif=0;
	m_iGifSize=0;
	m_iGlobalColorSize=0;
	m_bTransparentIndex=FALSE;
	m_iDelayTime=0;
	m_EndRun=0;
	m_dwSpeed=50;
	m_hRedrawBitmap=0;
	m_bLockBitmap=FALSE;
	flag=0;
	strcpy(filename,_T(""));
	m_bWindowOnly=TRUE;
	m_bNegotiatedWnd=FALSE;
	m_bWndLess=FALSE;
	m_bRunMode=1;
	m_bResizeNatural=TRUE;
	m_bRecomposeOnResize=TRUE;
	m_bGlass=FALSE;
}

CGif89a::~CGif89a(void)
{
 Stop();
 if(m_hRedrawBitmap!=0)DeleteObject(m_hRedrawBitmap);
 if(m_pcGlobalColorTable!=NULL)delete[] m_pcGlobalColorTable;
 if(m_pcGif!=NULL)delete[] m_pcGif;
}

DWORD WINAPI ThreadFunc(CGif89a* ptr)
{
	ptr->Play1();
	return 0;
}

BOOL CGif89a::Play1(void)
{
	HDC hDC,hMemDC,hMemDC1;
	HBITMAP hOldBitmap,hOldBitmap1,hBitmap,hPreviousBitmap;
	DWORD systimer1,systimer2,speed;
	hDC=::GetDC(m_hWnd);
	hMemDC=::CreateCompatibleDC(hDC);
	hMemDC1=::CreateCompatibleDC(hDC);
	m_hDC=hDC;
	hPreviousBitmap=0;
	while(m_bLockBitmap);
	m_bLockBitmap=TRUE;
	if(m_hRedrawBitmap!=0)DeleteObject(m_hRedrawBitmap);
	m_hRedrawBitmap=::CreateCompatibleBitmap(hDC,m_iGifWidth,m_iGifHeight);
	hOldBitmap1=(HBITMAP)SelectObject(hMemDC1,m_hRedrawBitmap);
	::BitBlt(hMemDC1,0,0,m_iGifWidth,m_iGifHeight,hDC,0,0,SRCCOPY);
	SelectObject(hMemDC1,hOldBitmap1);
	m_bLockBitmap=FALSE;
	m_iDisposalMethod=DISPOSAL_NOT;
	while(m_EndRun!=1)
	{
		systimer2=systimer1=GetTickCount();
		while(m_bLockBitmap);
		m_bLockBitmap=TRUE;
		hOldBitmap1=(HBITMAP)SelectObject(hMemDC1,m_hRedrawBitmap);
		//****************************************************
		//Restore Background
		switch(m_iDisposalMethod)
		{
		case DISPOSAL_NO:
			break;
		case DISPOSAL_NOT:
			break;
		case DISPOSAL_RESTBACK:
		case DISPOSAL_RESTORE:
			hOldBitmap=(HBITMAP)SelectObject(hMemDC,hPreviousBitmap);
			::BitBlt(hMemDC1,m_iLeft,m_iTop,m_iWidth,m_iHeight,hMemDC,0,0,SRCCOPY);
			SelectObject(hMemDC,hOldBitmap);
			DeleteObject(hPreviousBitmap);
			hPreviousBitmap=0;
			break;
		}
		m_iDisposalMethod=DISPOSAL_NO;
		//***************************************************
		//Start Output Image
		hBitmap=NextImage();
		switch(m_iDisposalMethod)
		{
		case DISPOSAL_NO:
			break;
		case DISPOSAL_NOT:
			break;
		case DISPOSAL_RESTBACK:
//			break;
		case DISPOSAL_RESTORE:
			hPreviousBitmap=::CreateCompatibleBitmap(hDC,m_iWidth,m_iHeight);
			hOldBitmap=(HBITMAP)SelectObject(hMemDC,hPreviousBitmap);
			::BitBlt(hMemDC,0,0,m_iWidth,m_iHeight,hMemDC1,m_iLeft,m_iTop,SRCCOPY);
			SelectObject(hMemDC,hOldBitmap);
			break;
		}
		hOldBitmap=(HBITMAP)SelectObject(hMemDC,hBitmap);
		if(m_bTransparentIndex)	
		{
			HBITMAP    bmAndBack, bmAndObject;
			HBITMAP    bmBackOld, bmObjectOld;
			HDC        hdcBack, hdcObject;
			COLORREF cColor;
			
			hdcBack=::CreateCompatibleDC(hDC);
			hdcObject=::CreateCompatibleDC(hDC);
			bmAndBack=CreateBitmap(m_iWidth,m_iHeight,1,1,NULL);
			bmAndObject=CreateBitmap(m_iWidth,m_iHeight,1,1,NULL);
			bmBackOld=(HBITMAP)SelectObject(hdcBack,bmAndBack);
			bmObjectOld=(HBITMAP)SelectObject(hdcObject,bmAndObject);
			cColor=SetBkColor(hMemDC,m_TransparentColor);
			::BitBlt(hdcObject,0,0,m_iWidth,m_iHeight,hMemDC,0,0,SRCCOPY);
			SetBkColor(hMemDC,cColor);
			::BitBlt(hdcBack,0,0,m_iWidth,m_iHeight,hdcObject,0,0,NOTSRCCOPY);
			::BitBlt(hMemDC1,m_iLeft,m_iTop,m_iWidth,m_iHeight,hdcObject,0,0,SRCAND);
			::BitBlt(hMemDC,0,0,m_iWidth,m_iHeight,hdcBack,0,0,SRCAND);
			::BitBlt(hMemDC1,m_iLeft,m_iTop,m_iWidth,m_iHeight,hMemDC,0,0,SRCPAINT);
			DeleteObject(SelectObject(hdcBack,bmBackOld));
			DeleteObject(SelectObject(hdcObject,bmObjectOld));
			DeleteDC(hdcBack);
			DeleteDC(hdcObject);
		}
		else 
		{
			::BitBlt(hMemDC1,m_iLeft,m_iTop,m_iWidth,m_iHeight,hMemDC,0,0,SRCCOPY);
		}
		SelectObject(hMemDC,hOldBitmap);
		DeleteObject(hBitmap);
		::BitBlt(hDC,0,0,m_iGifWidth,m_iGifHeight,hMemDC1,0,0,SRCCOPY);
		SelectObject(hMemDC1,hOldBitmap1);
		m_bLockBitmap=FALSE;
		if(m_iDelayTime!=0)speed=m_iDelayTime*10;else speed=m_dwSpeed;
		while((m_EndRun!=1)&&(speed>systimer2-systimer1))
		{
			Sleep(10);
			systimer2=GetTickCount();
		}
	}	
	if(hPreviousBitmap!=0)DeleteObject(hPreviousBitmap);
	DeleteDC(hMemDC);
	DeleteDC(hMemDC1);
	::ReleaseDC(m_hWnd,hDC);
	m_EndRun=2;
	return TRUE;
}

BOOL CGif89a::Load(LPCTSTR filename)
{
	HANDLE hFile;
	DWORD size,size1,readbyte;
	BYTE temp[13];
	if(m_bEmbed)return FALSE;
//free memory from previous image
	Stop();
	if(m_pcGlobalColorTable!=NULL)delete[] m_pcGlobalColorTable;
	if(m_pcGif!=NULL)delete[] m_pcGif;
	if(m_hRedrawBitmap!=0){DeleteObject(m_hRedrawBitmap);m_hRedrawBitmap=0;};
	m_pcGlobalColorTable=m_pcGif=0;
	m_iTotalReadByte=0;
	m_iGifSize=m_iGlobalColorSize=0;
	
	hFile=CreateFile(filename,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	if(INVALID_HANDLE_VALUE==hFile)return FALSE;
	size=GetFileSize(hFile,&size1);
	if(size==0xFFFFFFFF){CloseHandle(hFile);return FALSE;}
	ReadFile(hFile,temp,13,&readbyte,NULL);
	if((readbyte!=13)||((temp[0]!='G')||(temp[1]!='I')||(temp[2]!='F')||(temp[3]!='8')||((temp[4]!='7')&&(temp[4]!='9'))||(temp[5]!='a')))
	{
		CloseHandle(hFile);
		return FALSE;
	}
	m_iGifWidth=*(WORD*)(temp+6);
	m_iGifHeight=*(WORD*)(temp+8);
	m_iBackgroundColor=temp[11];
	if(temp[10]&0x80)
	{
		m_iGlobalColorSize=0x01<<((temp[10]&0x07)+1);
		m_pcGlobalColorTable=new BYTE[3*m_iGlobalColorSize];
		ReadFile(hFile,m_pcGlobalColorTable,3*m_iGlobalColorSize,&readbyte,NULL);
		if(readbyte!=3*m_iGlobalColorSize)
		{
			delete[] m_pcGlobalColorTable;
			m_pcGlobalColorTable=0;
			m_iGlobalColorSize=0;
			CloseHandle(hFile);
			return FALSE;
		}
	}

	m_iGifSize=size-3*m_iGlobalColorSize-12;
	m_pcGifTrack=m_pcGif=new BYTE[m_iGifSize];
	ReadFile(hFile,m_pcGif,m_iGifSize,&readbyte,NULL);
	CloseHandle(hFile);
	return TRUE;
}

HBITMAP CGif89a::FirstImage(void)
{
	m_pcGifTrack=m_pcGif;
	m_iTotalReadByte=0;
	return NextImage();
}

HBITMAP CGif89a::NextImage(void)
{
 	if(m_pcGif==NULL)return 0;
l1:	if(m_iTotalReadByte>m_iGifSize){m_pcGifTrack=m_pcGif;m_iTotalReadByte=0;return 0;}
	m_iTotalReadByte++;
	switch(*m_pcGifTrack++)
	{
	case 0x2C:
		return TakeIt();
		break;
	case 0x21:
			BYTE cSize;
			m_iTotalReadByte++;
			switch(*m_pcGifTrack++)
			{ 
			case 0xF9:
				m_pcGifTrack++;//block size
				m_iDisposalMethod=(*m_pcGifTrack)&28;
				m_bTransparentIndex=(*m_pcGifTrack++)&1;
				m_iDelayTime=*(WORD*)m_pcGifTrack;
				m_pcGifTrack+=2;
				m_iTransparentIndex=*m_pcGifTrack++;
				m_iTotalReadByte+=5;
				break;
			case 0xFE:
				while((cSize=*m_pcGifTrack)!=0){m_pcGifTrack+=cSize+1;m_iTotalReadByte+=cSize+1;if(m_iTotalReadByte>m_iGifSize)return 0;}
				break;
			case 0x01:
				m_pcGifTrack+=13;
				m_iTotalReadByte+=13;
				while((cSize=*m_pcGifTrack)!=0){m_pcGifTrack+=cSize+1;m_iTotalReadByte+=cSize+1;if(m_iTotalReadByte>m_iGifSize)return 0;}
				break;
			case 0xFF:
				m_pcGifTrack+=12;
				m_iTotalReadByte+=12;
				while((cSize=*m_pcGifTrack)!=0){m_pcGifTrack+=cSize+1;m_iTotalReadByte+=cSize+1;if(m_iTotalReadByte>m_iGifSize)return 0;}
				break;
			default:
				return FALSE;
			}
			m_pcGifTrack++;
			m_iTotalReadByte++;
			if(m_iTotalReadByte>m_iGifSize)return 0;
			goto l1;
			break;
	case 0x3B:
		m_pcGifTrack=m_pcGif;
		m_iTotalReadByte=0;
		goto l1;
	case 0:
		m_pcGifTrack=m_pcGif;
		m_iTotalReadByte=0;
		goto l1;
	default: 
		return FALSE;
	}
}

HBITMAP CGif89a::TakeIt(void)
{
	UINT uLocalColorTableSize;
	WORD code,oldcode,code1;
	int iFinishCode,iResetCode;
	int iPrimaryTableSize,iTableSize;
	BITMAPINFOHEADER *bitmapheader;
	BYTE *pcColorTable;
	BYTE *pcInfo;
	GIFTABLE *pcGifTable;
	HBITMAP hBitmap;
	m_iLeft=*(WORD*)m_pcGifTrack;
	m_pcGifTrack+=2;
	m_iTop=*(WORD*)m_pcGifTrack;
	m_pcGifTrack+=2;
	m_iWidth=*(WORD*)m_pcGifTrack;
	m_pcGifTrack+=2;
	m_iWidth1=((m_iWidth-1)|0x3)+1;
	m_iHeight=*(WORD*)m_pcGifTrack;
	m_pcGifTrack+=2;
	m_cPackedField=*m_pcGifTrack++;
	m_iTotalReadByte+=9;
	m_iMaxByte=m_iWidth1*m_iHeight;
	pcInfo=new BYTE[256*sizeof(RGBQUAD)+sizeof(BITMAPINFOHEADER)+m_iMaxByte+sizeof(GIFTABLE)*4096];
	//1-BITMAPINFOHEADER
	//2-COLORTABLE
	//3-Bitmap bits
	//4-GIFTABLE;
	bitmapheader=(BITMAPINFOHEADER*)pcInfo;
	pcColorTable=pcInfo+sizeof(BITMAPINFOHEADER);
	m_pcBitmap=pcColorTable+256*sizeof(RGBQUAD);
	pcGifTable=(GIFTABLE*)(m_pcBitmap+m_iMaxByte);
	for(int i=0;i<4096;i++)pcGifTable[i].previouscode=pcGifTable[i].nextcode=0;
	bitmapheader->biSize=sizeof(BITMAPINFOHEADER);
	bitmapheader->biWidth=m_iWidth;
	bitmapheader->biHeight=-m_iHeight;
	bitmapheader->biPlanes=1;
	bitmapheader->biBitCount=8;
	bitmapheader->biCompression=BI_RGB;
	bitmapheader->biSizeImage=0;
	bitmapheader->biXPelsPerMeter=0;
	bitmapheader->biYPelsPerMeter=0;
	bitmapheader->biClrUsed=256;
	bitmapheader->biClrImportant=256;

	if(m_cPackedField&0x80)
	{
		uLocalColorTableSize=1;
		uLocalColorTableSize<<=(m_cPackedField&7)+1;
		if(m_bTransparentIndex)
		{
			m_TransparentColor=RGB(m_pcGifTrack[m_iTransparentIndex*3],m_pcGifTrack[m_iTransparentIndex*3+1],m_pcGifTrack[m_iTransparentIndex*3+2]);
		}
		m_iTotalReadByte+=uLocalColorTableSize*3;
		for(UINT i=0;i<uLocalColorTableSize;i++)
		{
			pcColorTable[2]=*m_pcGifTrack++;
			pcColorTable[1]=*m_pcGifTrack++;
			pcColorTable[0]=*m_pcGifTrack++;
			pcColorTable[3]=0;
			pcColorTable+=4;
		}

	}
	else 
	{
		BYTE *pcGlobalColor=m_pcGlobalColorTable;
		if(m_bTransparentIndex)
		{
			m_TransparentColor=RGB(pcGlobalColor[m_iTransparentIndex*3],pcGlobalColor[m_iTransparentIndex*3+1],pcGlobalColor[m_iTransparentIndex*3+2]);
		}
		for(int i=0;i<m_iGlobalColorSize;i++)
		{
			pcColorTable[2]=*pcGlobalColor++;
			pcColorTable[1]=*pcGlobalColor++;
			pcColorTable[0]=*pcGlobalColor++;
			pcColorTable[3]=0;
			pcColorTable+=4;
		}
	}
	m_uPrimaryBitSize=m_uBitSize=(*m_pcGifTrack++);
	m_iTotalReadByte++;
	iPrimaryTableSize=iTableSize=(1<<m_uBitSize)+2;
	iFinishCode=iTableSize-1;
	iResetCode=iFinishCode-1;

	m_uPrimaryBitSize++;
	m_uBitSize++;
	m_uRemain=0;
	m_cCurentByte=0;
	m_uBlockSize=0;
	m_uReadByte=1;
	m_x=m_y=0;
	m_iPass=1;m_iRow=0;
	while((code=GetCode())!=iFinishCode)
	{
		if(code==iResetCode)
		{
			m_uBitSize=m_uPrimaryBitSize;
			iTableSize=iPrimaryTableSize;
			oldcode=GetCode();
			if(oldcode>iTableSize){delete[] pcInfo;return 0;}
			Output((BYTE)oldcode);
			continue;
		}
		if(code<iTableSize) //<code> exist in the string pcGifTable
		{
			code1=code;
			WORD code2=0;
			while(code1>=iPrimaryTableSize)
			{
				pcGifTable[code1].nextcode=code2;
				code2=code1;
				code1=pcGifTable[code1].previouscode;
				if(code1>=code2){delete[] pcInfo;return 0;}
			}
			Output((BYTE)code1);
			while(code2!=0)
			{
				Output(pcGifTable[code2].bit);
				code2=pcGifTable[code2].nextcode;
			}
			pcGifTable[iTableSize].bit=(BYTE)code1;
			pcGifTable[iTableSize].previouscode=oldcode;
			iTableSize++;
			if(iTableSize==(0x0001<<m_uBitSize))m_uBitSize++;
			if(m_uBitSize>12)m_uBitSize=12;
			oldcode=code;
		} 
		else    //<code> doesn't exist in the string pcGifTable
		{
			code1=oldcode;
			WORD code2=0;
			while(code1>=iPrimaryTableSize)
			{
				pcGifTable[code1].nextcode=code2;
				code2=code1;
				code1=pcGifTable[code1].previouscode;
				if(code1>=code2){delete[] pcInfo;return 0;}
			}
			Output((BYTE)code1);
			while(code2!=0)
			{
				Output(pcGifTable[code2].bit);
				code2=pcGifTable[code2].nextcode;
			}
			Output((BYTE)code1);
			pcGifTable[iTableSize].bit=(BYTE)code1;
			pcGifTable[iTableSize].previouscode=oldcode;
			iTableSize++;
			if(iTableSize==(0x0001<<m_uBitSize))m_uBitSize++;
			if(m_uBitSize>12)m_uBitSize=12;
			oldcode=code;
		}
	}

	hBitmap=CreateDIBitmap(m_hDC,bitmapheader,CBM_INIT,m_pcBitmap,(BITMAPINFO*)pcInfo,DIB_RGB_COLORS);		
	m_pcGifTrack++;
	m_iTotalReadByte++;
	delete[] pcInfo;
	return hBitmap;
}


LRESULT CGif89a::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	Stop();
	bHandled=TRUE;
	return 0;
}

LRESULT CGif89a::OnErase(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	bHandled=TRUE;
	return 1;
}

STDMETHODIMP CGif89a::get_Speed(long * pVal)
{
	*pVal=m_dwSpeed;
	return S_OK;
}

STDMETHODIMP CGif89a::put_Speed(long newVal)
{
	m_dwSpeed=newVal;
	m_bRequiresSave=TRUE;
	return S_OK;
}

STDMETHODIMP CGif89a::get_Glass(VARIANT_BOOL * pVal)
{
	// TODO: Add your implementation code here
	*pVal=m_bGlass;
	return S_OK;
}

STDMETHODIMP CGif89a::put_Glass(VARIANT_BOOL newVal)
{
	// TODO: Add your implementation code here
	m_bGlass=newVal;
	m_bRequiresSave=TRUE;
	return S_OK;
}

BOOL CALLBACK DialogProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static char s[]="[q2rsv2r`lfqwk2gk%U`dj`b2Qww?Vsdyjd\x08\x18\\}p2fsk2vwkv%\x7F`2`_d{i(%uqwwadsn}sRvbwkkwq<f}h\x1F\x0F\x32j`%a`w%zqfu(*=rer<bwjqlflwv<f}h=V{i{f}kDd~iw|=Msswk=0+<&";
	char s1[147];
	if((uMsg==WM_COMMAND)&&(wParam==IDC_BUTTON1))EndDialog(hwndDlg,1);
	if(uMsg==WM_INITDIALOG)
	{
		int i;
		for(i=0;i<147;i+=2)s1[i]=s[i]^0x12;
		for(i=1;i<147;i+=2)s1[i]=s[i]^0x5;
		s1[141]=0;
		SendDlgItemMessage(hwndDlg,IDC_EDIT1,WM_SETTEXT,0,(LPARAM)s1);
		return TRUE;
	}
	return FALSE;
}

STDMETHODIMP CGif89a::SetExtent(DWORD dwDrawAspect, SIZEL *psizel)
{
		m_sizeNatural=m_sizeExtent = *psizel;
		if (m_bRecomposeOnResize)
		{
			SendOnDataChange();
			FireViewChange();
		}
		return S_OK;
}

STDMETHODIMP CGif89a::GetExtent(DWORD dwDrawAspect, SIZEL *psizel)
{
	if(m_bAutoSize1&&(m_pcGif!=0))
	{
		SIZE s1;
		s1.cx=m_iGifWidth;
		s1.cy=m_iGifHeight;
		AtlPixelToHiMetric(&s1,psizel);
		m_sizeNatural=*psizel;
		m_sizeExtent=*psizel;
	}
	else *psizel=m_sizeExtent;
	return S_OK;
}

STDMETHODIMP CGif89a::get_Embed(VARIANT_BOOL * pVal)
{
	// TODO: Add your implementation code here
	*pVal=m_bEmbed;
	return S_OK;
}

STDMETHODIMP CGif89a::put_Embed(VARIANT_BOOL newVal)
{
	// TODO: Add your implementation code here
	m_bEmbed=newVal;
	return S_OK;
}

HRESULT CGif89a::IPersistStreamInit_Load(LPSTREAM pStm, ATL_PROPMAP_ENTRY* pMap)
{
	_ASSERTE(pMap != NULL);
	HRESULT hr = S_OK;
	DWORD dwVer;
	hr = pStm->Read(&dwVer, sizeof(DWORD), NULL);
	if (SUCCEEDED(hr) && dwVer <= _ATL_VER)
		hr = pStm->Read(&m_sizeExtent, sizeof(m_sizeExtent), NULL);
	if (FAILED(hr))
		return hr;
///m_bembeded
	hr = pStm->Read(&m_bEmbed, sizeof(m_bEmbed), NULL);
	if (FAILED(hr))	return hr;
	if(m_bEmbed)
	{
		if(m_pcGlobalColorTable!=NULL)delete[] m_pcGlobalColorTable;
		if(m_pcGif!=NULL)delete[] m_pcGif;
		if(m_hRedrawBitmap!=0){DeleteObject(m_hRedrawBitmap);m_hRedrawBitmap=0;};
		hr = pStm->Read(&m_iGifWidth, sizeof(m_iGifWidth), NULL);
		if (FAILED(hr))	return hr;
		hr = pStm->Read(&m_iGifHeight, sizeof(m_iGifHeight), NULL);
		if (FAILED(hr))	return hr;
		hr = pStm->Read(&m_iGlobalColorSize, sizeof(m_iGlobalColorSize), NULL);
		if (FAILED(hr))	return hr;
		if(m_iGlobalColorSize!=0)
		{
			m_pcGlobalColorTable=new BYTE[m_iGlobalColorSize*3];
			hr = pStm->Read(m_pcGlobalColorTable, m_iGlobalColorSize*3, NULL);
			if (FAILED(hr)){delete m_pcGlobalColorTable;return hr;}
		}
		hr = pStm->Read(&m_iGifSize, sizeof(m_iGifSize), NULL);
		if (FAILED(hr)){delete m_pcGlobalColorTable;return hr;}
		if(m_iGifSize!=0)
		{
			m_pcGif=new BYTE[m_iGifSize];
			hr = pStm->Read(m_pcGif, m_iGifSize, NULL);
			if (FAILED(hr)){delete m_pcGlobalColorTable;delete m_pcGif;return hr;}
		}
	}

//***********************************	
/*	CComPtr<IDispatch> pDispatch;
	const IID* piidOld = NULL;
	for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)
	{
		if (pMap[i].szDesc == NULL)
			continue;
		CComVariant var;

		HRESULT hr = var.ReadFromStream(pStm);
		if (FAILED(hr))
			break;

		if(pMap[i].piidDispatch != piidOld)
		{
			if(FAILED(ControlQueryInterface(*pMap[i].piidDispatch, (void**)&pDispatch)))
			{
				ATLTRACE(_T("Failed to get a dispatch pointer for property #%i\n"), i);
				hr = E_FAIL;
				break;
			}
			piidOld = pMap[i].piidDispatch;
		}

		if (FAILED(CComDispatchDriver::PutProperty(pDispatch, pMap[i].dispid, &var)))
		{
			ATLTRACE(_T("Invoked failed on DISPID %x\n"), pMap[i].dispid);
			hr = E_FAIL;
			break;
		}
	}
	return hr;*/
	return IPersistStreamInitImpl<CGif89a>::IPersistStreamInit_Load(pStm, pMap);
}

HRESULT CGif89a::IPersistStreamInit_Save(LPSTREAM pStm, BOOL /* fClearDirty */, ATL_PROPMAP_ENTRY* pMap)
{
	_ASSERTE(pMap != NULL);
	DWORD dw = _ATL_VER;
	HRESULT hr = pStm->Write(&dw, sizeof(DWORD), NULL);
	if (FAILED(hr))
		return hr;
	hr = pStm->Write(&m_sizeExtent, sizeof(m_sizeExtent), NULL);
	if (FAILED(hr))
		return hr;
	//m_bEmbed
	hr = pStm->Write(&m_bEmbed, sizeof(m_bEmbed), NULL);
	if (FAILED(hr))	return hr;
	if(m_bEmbed)
	{
		hr = pStm->Write(&m_iGifWidth, sizeof(m_iGifWidth), NULL);
		if (FAILED(hr))	return hr;
		hr = pStm->Write(&m_iGifHeight, sizeof(m_iGifHeight), NULL);
		if (FAILED(hr))	return hr;
		hr = pStm->Write(&m_iGlobalColorSize, sizeof(m_iGlobalColorSize), NULL);
		if (FAILED(hr))	return hr;
		if(m_iGlobalColorSize!=0)
		{
			hr = pStm->Write(m_pcGlobalColorTable, m_iGlobalColorSize*3, NULL);
			if (FAILED(hr))return hr;
		}
		hr = pStm->Write(&m_iGifSize, sizeof(m_iGifSize), NULL);
		if (FAILED(hr))return hr;
		if(m_iGifSize!=0)
		{
			hr = pStm->Write(m_pcGif, m_iGifSize, NULL);
			if (FAILED(hr))return hr;
		}
	}
	//*****************************************************************
/*	CComPtr<IDispatch> pDispatch;
	const IID* piidOld = NULL;
	for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)
	{
		if (pMap[i].szDesc == NULL)
			continue;
		CComVariant var;

		if(pMap[i].piidDispatch != piidOld)
		{
			if(FAILED(ControlQueryInterface(*pMap[i].piidDispatch, (void**)&pDispatch)))
			{
				ATLTRACE(_T("Failed to get a dispatch pointer for property #%i\n"), i);
				hr = E_FAIL;
				break;
			}
			piidOld = pMap[i].piidDispatch;
		}

		if (FAILED(CComDispatchDriver::GetProperty(pDispatch, pMap[i].dispid, &var)))
		{
			ATLTRACE(_T("Invoked failed on DISPID %x\n"), pMap[i].dispid);
			hr = E_FAIL;
			break;
		}

		HRESULT hr = var.WriteToStream(pStm);
		if (FAILED(hr))
			break;
	}
	if (SUCCEEDED(hr))
		m_bRequiresSave = FALSE;

	return hr;*/
	return IPersistStreamInitImpl<CGif89a>::IPersistStreamInit_Save(pStm, TRUE, pMap);
}