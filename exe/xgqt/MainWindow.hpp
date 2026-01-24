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
}

using namespace yq;
using yq::gluon::GraphCanvas;
using yq::gluon::GNodePalette;
using namespace yq::tachyon;

class MainWindow : public YMain {
    YQ_TACHYON_DECLARE(MainWindow, YMain)
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    
    virtual MainWindow*     newMain() override;
    
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
    
private:
    bool    saveTab(GraphCanvas&, const QString&);

    QPrinter    m_printer;
};
