////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppWindow.hpp"
#include <yq/core/Logging.hpp>
#include <yq/graph/GDocument.hpp>
#include <yq/graph/GMetaGraph.hpp>
#include <yq/graphQt/GNodePalette.hpp>
#include <yq/graphQt/GraphCanvas.hpp>
#include <yq/graphQt/GraphScene.hpp>
#include <yq/graphicsQt/GraphicsToolBar.hpp>
#include <yq/vkqt/app/YMainMetaWriter.hpp>
#include <yq/xg/XGElement.hpp>
//#include <yq/xg/XGXmlIO.hpp>

#include <QFileDialog>
#include <QPainter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>

YQ_TACHYON_IMPLEMENT(AppWindow)

void AppWindow::init_meta()
{
    auto w = writer<AppWindow>();
    w.description("Executive Flow Graph Main Window");
}

AppWindow::AppWindow()
{
    activateTabs();
    enableClosableTabs();
    enableAutoEnableCmds();


    setWindowTitle("Executive Graph");
    resize(1920, 1080);
    
    status("Executive Graph");
    
    addAction("new", "New").connect(this, &AppWindow::cmdFileNew);
    addAction("open", "Open").connect(this, &AppWindow::cmdFileOpen);
    addAction("save", "Save").connect(this, &AppWindow::cmdFileSave);
    addAction("saveas", "Save As").connect(this, &AppWindow::cmdFileSaveAs);
    addAction("palette", "Palette").connect(this, &AppWindow::cmdViewPalette);
    addAction("print", "Print").connect(this, &AppWindow::cmdFilePrint);

    makeMenu("file", "File", QStringList() << "new" << "open" << "save" << "saveas" << "print" );
    makeMenu("edit", "Edit");
    makeMenu("view", "View", QStringList() << "palette");
    
    m_toolbar   = new GraphicsToolBar;
    connect(m_toolbar, &GraphicsToolBar::clicked, this, &AppWindow::cmdToolChange);
    
    // add...
    
    addToolBar(Qt::TopToolBarArea, m_toolbar);
    
    cmdViewPalette();
}

AppWindow::~AppWindow()
{
}

void    AppWindow::activeChanged() 
{
    YMain::activeChanged();
    if(GraphCanvas* cvs = currentCanvas()){
        m_toolbar -> setActive( cvs -> currentTool() );
    }
}

void    AppWindow::cmdFileNew()
{
    cmdNewTab();
}

void    AppWindow::cmdFileOpen()
{
    QString dir;
    if(GraphCanvas*     cvs = currentCanvas()){
        dir = cvs->dirname();
    }

    QString file    = QFileDialog::getOpenFileName(
        this, tr("Open Executive Graph File"), dir,
        "Executive Graph Files (*.xg)"
    );
    if(file.isEmpty())
        return;
    
    cmdOpenTab(file);
}

void    AppWindow::cmdFilePrint()
{
    GraphCanvas*     cvs = currentCanvas();
    if(!cvs)
        return ;
    
     //QPrinter printer();
    QPrintDialog dialog(&m_printer, this);
    if(dialog.exec() != QDialog::Accepted)
        return ;

    QPainter    painter(&m_printer);
    cvs->scene()->print(&painter);
    //m_view->drawTo(painter);
}


void    AppWindow::cmdFileSave()
{
    GraphCanvas*     cvs = currentCanvas();
    if(!cvs)
        return ;
    
    QString file   = cvs -> filename();
    if(file.isEmpty()){
        cmdFileSaveAs();
    } else {
        saveTab(*cvs, file);
    }
}

void    AppWindow::cmdFileSaveAs()
{
    GraphCanvas*     cvs = currentCanvas();
    if(!cvs)
        return ;

    QString file    = QFileDialog::getSaveFileName(
        this, tr("Save Exective Graph File"), cvs->dirname(),
        "Executive Graph Files (*.xg)"
    );
    if(file.isEmpty())
        return;
    saveTab(*cvs, file);
}

void    AppWindow::cmdNewTab()
{
    GraphCanvas* cvs = new GraphCanvas;
    cvs -> updateTitle();
    addWindow(cvs);
}

void    AppWindow::cmdOpenTab(const QString& file)
{
    auto doc    = GDocument::IO::load(std::filesystem::path(file.toStdString()));
    if(!doc){
        status(tr("Unable to load file %1").arg(file));
        return ;
    }
    
    GraphCanvas* cvs = new GraphCanvas;
    cvs -> set(*doc);
    addWindow(cvs);
}

void    AppWindow::cmdToolChange(uint64_t i)
{
    GraphCanvas*     cvs = currentCanvas();
    if(!cvs)
        return ;
    cvs -> setTool(i);
    m_toolbar->setActive(cvs -> currentTool());
}

void    AppWindow::cmdViewPalette()
{
    auto manif  = XGElementMeta::create_manifest();
    if(!manif)
        return ;
        
    GNodePalette*    pal = new GNodePalette(manif->nodes());

    //XGPaletteQt*    pal = new XGPaletteQt;
    //  we'll do stuff....
    addDock(Qt::LeftDockWidgetArea, pal);
}

GraphCanvas*     AppWindow::currentCanvas()
{
    return dynamic_cast<GraphCanvas*>(activeWindow());
}

AppWindow*     AppWindow::newMain() 
{
    return Tachyon::create<AppWindow>();
}

bool    AppWindow::saveTab(GraphCanvas& cvs, const QString& fp)
{
    GDocumentCPtr  doc = cvs.get();
    std::error_code ec = doc -> save_to(std::filesystem::path(fp.toStdString()));
    if(ec != std::error_code()){
        status(tr("Unable to save file '%1': %2").arg(fp).arg(ec.message()));
        return false;
    }
    cvs.updateTitle();
    return true;
}



#include "moc_AppWindow.cpp"
