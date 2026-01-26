////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YMain.hpp>
#include <yq/typedef/g_document.hpp>
#include <QPrinter>

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
    
protected: 
    void            activeChanged() override;
    
private slots:
    void    cmdToolChange(uint64_t);
    
private:
    bool    saveTab(GraphCanvas&, const QString&);

    QPrinter            m_printer;
    GraphicsToolBar*    m_toolbar   = nullptr;
};
