#ifndef __UICOMBO_H__
#define __UICOMBO_H__

#pragma once

namespace DuiLib {
/////////////////////////////////////////////////////////////////////////////////////
//

class CComboWnd;

class DUILIB_API CComboUI : public CContainerUI, public IListOwnerUI
{
    friend class CComboWnd;
public:
    CComboUI();

    LPCTSTR GetClass() const;
    LPVOID GetInterface(LPCTSTR pstrName);

    void DoInit();
    UINT GetControlFlags() const;

    CDuiString GetText() const;
    void SetEnabled(bool bEnable = true);

    CDuiString GetDropBoxAttributeList();
    void SetDropBoxAttributeList(LPCTSTR pstrList);
    SIZE GetDropBoxSize() const;
    void SetDropBoxSize(SIZE szDropBox);

    int GetCurSel() const;
	bool GetSelectCloseFlag();
	void SetSelectCloseFlag(bool flag);
    bool SelectItem(int iIndex, bool bTakeFocus = false, bool bTriggerEvent=true);
    bool ExpandItem(int iIndex, bool bExpand = true);
    int GetExpandedItem() const;

    bool SetItemIndex(CControlUI* pControl, int iNewIndex);
    bool SetMultiItemIndex(CControlUI* pStartControl, int iCount, int iNewStartIndex);
    bool Add(CControlUI* pControl);
    bool AddAt(CControlUI* pControl, int iIndex);
    bool Remove(CControlUI* pControl, bool bDoNotDestroy=false);
    bool RemoveAt(int iIndex, bool bDoNotDestroy=false);
    void RemoveAll();

    bool Activate();

	bool GetShowText() const;
	void SetShowText(bool flag);
    RECT GetTextPadding() const;
    void SetTextPadding(RECT rc);
    LPCTSTR GetNormalImage() const;
    void SetNormalImage(LPCTSTR pStrImage);
    LPCTSTR GetHotImage() const;
    void SetHotImage(LPCTSTR pStrImage);
    LPCTSTR GetPushedImage() const;
    void SetPushedImage(LPCTSTR pStrImage);
    LPCTSTR GetFocusedImage() const;
    void SetFocusedImage(LPCTSTR pStrImage);
    LPCTSTR GetDisabledImage() const;
    void SetDisabledImage(LPCTSTR pStrImage);

    TListInfoUI* GetListInfo();
    UINT GetItemFixedHeight();
    void SetItemFixedHeight(UINT nHeight);
    int GetItemFont(int index);
    void SetItemFont(int index);
    UINT GetItemTextStyle();
    void SetItemTextStyle(UINT uStyle);
	RECT GetItemTextPadding() const;
    void SetItemTextPadding(RECT rc);
	DWORD GetItemTextColor() const;
    void SetItemTextColor(DWORD dwTextColor);
	DWORD GetItemBkColor() const;
    void SetItemBkColor(DWORD dwBkColor);
	LPCTSTR GetItemBkImage() const;
    void SetItemBkImage(LPCTSTR pStrImage);
    bool IsAlternateBk() const;
    void SetAlternateBk(bool bAlternateBk);
	DWORD GetSelectedItemTextColor() const;
    void SetSelectedItemTextColor(DWORD dwTextColor);
	DWORD GetSelectedItemBkColor() const;
    void SetSelectedItemBkColor(DWORD dwBkColor);
	LPCTSTR GetSelectedItemImage() const;
    void SetSelectedItemImage(LPCTSTR pStrImage);
	DWORD GetHotItemTextColor() const;
    void SetHotItemTextColor(DWORD dwTextColor);
	DWORD GetHotItemBkColor() const;
    void SetHotItemBkColor(DWORD dwBkColor);
	LPCTSTR GetHotItemImage() const;
    void SetHotItemImage(LPCTSTR pStrImage);
	DWORD GetDisabledItemTextColor() const;
    void SetDisabledItemTextColor(DWORD dwTextColor);
	DWORD GetDisabledItemBkColor() const;
    void SetDisabledItemBkColor(DWORD dwBkColor);
	LPCTSTR GetDisabledItemImage() const;
    void SetDisabledItemImage(LPCTSTR pStrImage);
    int GetItemHLineSize() const;
    void SetItemHLineSize(int iSize);
    DWORD GetItemHLineColor() const;
    void SetItemHLineColor(DWORD dwLineColor);
    int GetItemVLineSize() const;
    void SetItemVLineSize(int iSize);
	DWORD GetItemVLineColor() const;
    void SetItemVLineColor(DWORD dwLineColor);
    bool IsItemShowHtml();
    void SetItemShowHtml(bool bShowHtml = true);

    SIZE EstimateSize(SIZE szAvailable);
	void SetPos(RECT rc, bool bNeedInvalidate = true);
	void Move(SIZE szOffset, bool bNeedInvalidate = true);
    void DoEvent(TEventUI& event);
    /** 支持的属性
     *  textpadding 文字间隙 left,top,right,bottom
     *  showtext    bool 
     *  normalimage string
     *  hotimage
     *  pushedimage
     *  focusedimage
     *  disabledimage
     *  dropbox string
     *  dropboxsize 弹出对话框的大小设置 cx,cy
     *  itemheight  每一项的高度 int
     *  itemalign   每一项的对齐方式 left/center/right
     *  itemtextpadding 每一项的文字间隙 left,top,right,bottom
     *  itemtextcolor  每一项的文字颜色 十六进制 0xAARRGGBB/0xAARRGGBB
     *  itembkcolor 每一项的背景颜色 十六进制 0xAARRGGBB/0xAARRGGBB
     *  itembkimage 每一项的背景图片路径 string
     *  itemaltbk   bool 是否使用隔行背景
     *  itemselectedtextcolor   选中项的字体颜色 十六进制 0xAARRGGBB/0xAARRGGBB
     *  itemselectedbkcolor 选中项的背景颜色 十六进制 0xAARRGGBB/0xAARRGGBB
     *  itemselectedimage 选中项的背景图片
     *  itemhottextcolor  鼠标悬停时的字体颜色  十六进制 0xAARRGGBB/0xAARRGGBB
     *  itemhotbkcolor  鼠标悬停时的背景颜色  十六进制 0xAARRGGBB/0xAARRGGBB
     *  itemhotimage    鼠标悬停时的背景图片路径 string
     *  itemdisabledbkcolor 禁用项的背景颜色  十六进制 0xAARRGGBB/0xAARRGGBB
     *  itemdisabledimage   禁用项的背景图片路径 string
     *  itemvlinesize   ?? int
     *  itemhlinesize   ?? int
     *  itemhlinecolor  ?? 十六进制 0xAARRGGBB/0xAARRGGBB
     *  itemshowhtml    项是否显示html文本 bool
     **/
    void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
    
    bool DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);
    void PaintText(HDC hDC);
    void PaintStatusImage(HDC hDC);

protected:
    CComboWnd* m_pWindow;

    int m_iCurSel;
	bool m_bShowText;
	bool m_bSelectCloseFlag;
    RECT m_rcTextPadding;
    CDuiString m_sDropBoxAttributes;
    SIZE m_szDropBox;
    UINT m_uButtonState;

	TDrawInfo m_diNormal;
    TDrawInfo m_diHot;
    TDrawInfo m_diPushed;
    TDrawInfo m_diFocused;
    TDrawInfo m_diDisabled;

    TListInfoUI m_ListInfo;
};

} // namespace DuiLib

#endif // __UICOMBO_H__
