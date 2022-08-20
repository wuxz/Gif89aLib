// Gif89a.h : Declaration of the CGif89a

#ifndef __GIF89A_H_
#define __GIF89A_H_

#include "resource.h"       // main symbols

#define DISPOSAL_NO 0
#define DISPOSAL_NOT 4
#define DISPOSAL_RESTBACK 8
#define DISPOSAL_RESTORE 12

typedef struct
{
	BYTE bit;
	WORD previouscode;
	WORD nextcode;
} GIFTABLE;

/////////////////////////////////////////////////////////////////////////////
// CGif89a
class ATL_NO_VTABLE CGif89a : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGif89a, &CLSID_Gif89a>,
	public CComControl<CGif89a>,
	public CStockPropImpl<CGif89a, IGif89a, &IID_IGif89a, &LIBID_GIF89Lib>,
	public IProvideClassInfo2Impl<&CLSID_Gif89a, NULL, &LIBID_GIF89Lib>,
	public IPersistStreamInitImpl<CGif89a>,
	public IPersistStorageImpl<CGif89a>,
	public IQuickActivateImpl<CGif89a>,
	public IOleControlImpl<CGif89a>,
	public IOleObjectImpl<CGif89a>,
	public IOleInPlaceActiveObjectImpl<CGif89a>,
	public IViewObjectExImpl<CGif89a>,
	public IOleInPlaceObjectWindowlessImpl<CGif89a>,
	public IDataObjectImpl<CGif89a>
//	public IConnectionPointContainerImpl<CGif89a>,
//	public IPropertyNotifySinkCP<CGif89a>,
//	public ISpecifyPropertyPagesImpl<CGif89a>
{
protected:
	BOOL	m_bAutoStart;
	BOOL	m_bEmbed;
	BYTE	m_cCurentByte,m_cPackedField;
	UINT	m_uBitSize,m_uPrimaryBitSize;
	UINT	m_uRemain,m_uReadByte,m_uBlockSize;
	int		m_iWidth,m_iHeight;
	int		m_iTop,m_iLeft;
	int		m_iFinishCode,m_iResetCode;
	int		m_iPass,m_iRow;
	int		m_iWidth1;
	int		m_iBackgroundColor;
	int		m_iGifSize;
	int		m_x,m_y;
	int		m_iGlobalColorSize;
	int		m_iDisposalMethod;
	BOOL	m_bTransparentIndex;
	int		m_iTransparentIndex;
	int		m_iDelayTime;
	int		m_iTotalReadByte;
	int		m_iMaxByte;
	DWORD	m_dwSpeed;
	COLORREF m_TransparentColor;
	HDC		m_hDC;
	BYTE*	m_pcGlobalColorTable;
	BYTE*	m_pcBitmap;
	BYTE*	m_pcGif;
	BYTE*	m_pcGifTrack; 
	BOOL	m_bGlass;
	volatile int m_EndRun;
	HBITMAP m_hRedrawBitmap;
	int		m_iGifWidth,m_iGifHeight;
	volatile BOOL	m_bLockBitmap;
	TCHAR	filename[_MAX_PATH];
	int		flag;
	BOOL	m_bRunMode;
	BOOL	m_bAutoSize1;
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnErase(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
public:
	CGif89a();
	~CGif89a();
	BOOL Load(LPCTSTR name);
	BOOL Play1(void);
	HBITMAP FirstImage(void);
	HBITMAP NextImage(void);
	HBITMAP TakeIt(void);
	void Output(BYTE bit)
	{
		int tmp;
		if(m_cPackedField&0x40)
		{
			if(m_x==m_iWidth)
			{
				m_x=0;
				if(m_iPass==1)m_iRow+=8;
				if(m_iPass==2)m_iRow+=8;
				if(m_iPass==3)m_iRow+=4;
				if(m_iPass==4)m_iRow+=2;
				if(m_iRow>=m_iHeight){m_iPass+=1;m_iRow=16>>m_iPass;}
			}
			tmp=m_iRow*m_iWidth1+m_x;
			m_pcBitmap[tmp]=bit;
			m_x++;
		}
		else
		{
			if(m_x==m_iWidth){m_x=0;m_y++;}
			tmp=m_y*m_iWidth1+m_x;
			m_x++;
		}
		if(tmp>m_iMaxByte)return;
		m_pcBitmap[tmp]=bit;
	}

	BYTE GetByte(void)
	{
		if(m_uReadByte>=m_uBlockSize)
		{
			m_uBlockSize=*m_pcGifTrack++;
			m_uReadByte=0;
			m_iTotalReadByte+=m_uBlockSize+1;
			if(m_iTotalReadByte>m_iGifSize){m_iTotalReadByte-=m_uBlockSize+1;return 0xFF;}
			if(m_uBlockSize==0){m_pcGifTrack--;m_iTotalReadByte--;return 0xFF;}
		}
		m_uReadByte++;
		return *m_pcGifTrack++;
	}

	WORD GetCode(void)
	{
		UINT tmp1;
		BYTE tmp;
		tmp=1;
		if(m_uRemain>=m_uBitSize)
		{
			tmp<<=m_uBitSize;
			tmp--;
			tmp1=m_cCurentByte&tmp;
			m_cCurentByte>>=m_uBitSize;
			m_uRemain-=m_uBitSize;
		}
		else
		{
			tmp<<=m_uRemain;
			tmp--;
			tmp1=m_cCurentByte;
			m_cCurentByte=GetByte();
			tmp=1;
			if(8>=(m_uBitSize-m_uRemain))
			{
				tmp<<=(m_uBitSize-m_uRemain);
				tmp--;
				tmp1=(((UINT)(m_cCurentByte&tmp))<<m_uRemain)+tmp1;
				m_cCurentByte>>=(m_uBitSize-m_uRemain);
				m_uRemain=8-(m_uBitSize-m_uRemain);
			}
			else
			{
				tmp1=(((UINT)(m_cCurentByte))<<m_uRemain)+tmp1;
				m_cCurentByte=GetByte();
				tmp<<=m_uBitSize-m_uRemain-8;
				tmp--;
				tmp1=(((UINT)(m_cCurentByte&tmp))<<(m_uRemain+8))+tmp1;
				m_cCurentByte>>=m_uBitSize-m_uRemain-8;
				m_uRemain=8-(m_uBitSize-m_uRemain-8);
			}
		}
		return tmp1;
	}


DECLARE_REGISTRY_RESOURCEID(IDR_GIF89A)

BEGIN_COM_MAP(CGif89a)
	COM_INTERFACE_ENTRY(IGif89a)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IMPL(IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY_IMPL(IOleControl)
	COM_INTERFACE_ENTRY_IMPL(IOleObject)
	COM_INTERFACE_ENTRY_IMPL(IQuickActivate)
	COM_INTERFACE_ENTRY_IMPL(IPersistStorage)
	COM_INTERFACE_ENTRY_IMPL(IPersistStreamInit)
//	COM_INTERFACE_ENTRY_IMPL(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
//	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CGif89a)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	PROP_ENTRY("AutoStart",4,CLSID_NULL)
	PROP_ENTRY("Speed",5,CLSID_NULL)
	PROP_ENTRY("Glass",6,CLSID_NULL)
	PROP_ENTRY("AutoSize",7,CLSID_NULL)
	PROP_ENTRY("FileName",9,CLSID_NULL)
//	PROP_PAGE(CLSID_About)
END_PROPERTY_MAP()


/*BEGIN_CONNECTION_POINT_MAP(CGif89a)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()
*/
BEGIN_MSG_MAP(CGif89a)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
	MESSAGE_HANDLER(WM_DESTROY, OnClose)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnErase)
END_MSG_MAP()


// IViewObjectEx
	STDMETHOD(GetViewStatus)(DWORD* pdwStatus)
	{
		ATLTRACE(_T("IViewObjectExImpl::GetViewStatus\n"));
		*pdwStatus = VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE;
		return S_OK;
	}

// IGif89a
public:
	STDMETHOD(get_Embed)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Embed)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Glass)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Glass)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Speed)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Speed)(/*[in]*/ long newVal);
	STDMETHOD(put_AutoSize)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_AutoSize)(/*[in]*/ VARIANT_BOOL *newVal);
	STDMETHOD(get_AutoStart)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_AutoStart)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FileName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FileName)(/*[in]*/  BSTR newVal);
	STDMETHOD(Stop)();
	STDMETHOD(Play)();
	STDMETHOD(AboutBox)();
	STDMETHOD(SetExtent)(DWORD dwDrawAspect, SIZEL *psizel);
	STDMETHOD(GetExtent)(DWORD dwDrawAspect, SIZEL *psizel);
	HRESULT OnDraw(ATL_DRAWINFO& di);
	HRESULT IPersistStreamInit_Save(LPSTREAM pStm, BOOL /* fClearDirty */, ATL_PROPMAP_ENTRY* pMap);
	HRESULT IPersistStreamInit_Load(LPSTREAM pStm, ATL_PROPMAP_ENTRY* pMap);
};

#endif //__GIF89A_H_
