////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YMain.hpp>
#include <yq/typedef/g_document.hpp>
#include <yq/typedef/url.hpp>
#include <QPrinter>

namespace yq {
    class GGraph;
}

namespace yq::gluon {
    class GraphCanvas;
    class GNodePalette;
    class GraphicsToolBar;
}

using namespace yq;
using namespace yq::gluon;
using namespace yq::tachyon;

class AppWindow : public YMain {
    YQ_TACHYON_DECLARE(AppWindow, YMain)
    Q_OBJECT
public:
    AppWindow();
    ~AppWindow();
    
    virtual AppWindow*     newMain() override;
    
    GraphCanvas*     currentCanvas();
    
    
    // will need measures to prevent duplicate opens
    
    static void init_meta();
    
public slots:
    void    cmdNewTab();
    void    cmdOpenTab(const QString&);
    
    void    cmdFileNew();
    void    cmdFileOpen();
    void    cmdFileSave();
    void    cmdFileSaveAs();
    void    cmdFilePrint();
    void    cmdViewPalette();
    void    cmdViewRefresh();
    void    cmdSelectAll();
    void    cmdSelectNone();
    
    void    cmdEditProperties();
    
protected: 
    void            activeChanged() override;
    
private slots:
    void    cmdToolChange(uint64_t);
    
    void    ctxCanvas(uint64_t);
    void    dblClick(uint64_t);
    
private:
    bool    saveTab(GraphCanvas&, const QString&);

    void    createTab(GGraph, const Url& u);

    uint64_t            m_dataId        = 0;
    QPrinter            m_printer;
    GraphicsToolBar*    m_toolbar       = nullptr;
    
    QMenu*              m_docPopup      = nullptr;
    QMenu*              m_nodePopup     = nullptr;
    QMenu*              m_edgePopup     = nullptr;
    QMenu*              m_basePopup     = nullptr;
    QMenu*              m_linePopup     = nullptr;
    QMenu*              m_graphPopup    = nullptr;
    QMenu*              m_portPopup     = nullptr;
    QMenu*              m_shapePopup    = nullptr;
    QMenu*              m_textPopup     = nullptr;
};
