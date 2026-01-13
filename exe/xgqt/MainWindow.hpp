////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YMain.hpp>
#include <yq/typedef/xg_document.hpp>

namespace yq::tachyon {
    class XGCanvasQt;
}

using namespace yq;
using namespace yq::tachyon;

class MainWindow : public YMain {
    YQ_TACHYON_DECLARE(MainWindow, YMain)
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    
    virtual MainWindow*     newMain() override;
    
    XGCanvasQt*     currentCanvas();
    
    
    // will need measures to prevent duplicate opens
    
    static void init_meta();
    
public slots:
    void    cmdNewTab();
    void    cmdOpenTab(const QString&);
    
    void    cmdFileNew();
    void    cmdFileOpen();
    void    cmdFileSave();
    void    cmdFileSaveAs();
    
private:
    void    newTab(const XGDocumentPtr&);
    bool    saveTab(XGCanvasQt&, const QString&);
};
