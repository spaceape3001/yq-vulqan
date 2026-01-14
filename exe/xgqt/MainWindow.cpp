////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWindow.hpp"
#include <yq/core/Logging.hpp>
#include <yq/vkqt/app/YMainMetaWriter.hpp>
#include <yq/xgqt/XGCanvasQt.hpp>
#include <yq/xgqt/XGPaletteQt.hpp>
#include <yq/xg/XGDocument.hpp>
#include <yq/xg/XGXmlIO.hpp>
#include <QFileDialog>

YQ_TACHYON_IMPLEMENT(MainWindow)

void MainWindow::init_meta()
{
    auto w = writer<MainWindow>();
    w.description("Executive Flow Graph Main Window");
}

MainWindow::MainWindow()
{
    activateTabs();
    enableClosableTabs();
    enableAutoEnableCmds();


    setWindowTitle("Executive Graph");
    resize(1920, 1080);
    
    status("Executive Graph");
    
    addAction("new", "New").connect(this, &MainWindow::cmdFileNew);
    addAction("open", "Open").connect(this, &MainWindow::cmdFileOpen);
    addAction("save", "Save").connect(this, &MainWindow::cmdFileSave);
    addAction("saveas", "Save As").connect(this, &MainWindow::cmdFileSaveAs);
    addAction("palette", "Palette").connect(this, &MainWindow::cmdViewPalette);

    makeMenu("file", "File", QStringList() << "new" << "open" << "save" << "saveas" );
    makeMenu("edit", "Edit");
    makeMenu("view", "View", QStringList() << "palette");
    
    cmdViewPalette();
}

MainWindow::~MainWindow()
{
}

void    MainWindow::cmdFileNew()
{
    cmdNewTab();
}

void    MainWindow::cmdFileOpen()
{
    QString dir;
    if(XGCanvasQt*     cvs = currentCanvas()){
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

void    MainWindow::cmdFileSave()
{
    XGCanvasQt*     cvs = currentCanvas();
    if(!cvs)
        return ;
    
    QString file   = cvs -> filename();
    if(file.isEmpty()){
        cmdFileSaveAs();
    } else {
        saveTab(*cvs, file);
    }
}

void    MainWindow::cmdFileSaveAs()
{
    XGCanvasQt*     cvs = currentCanvas();
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

void    MainWindow::cmdNewTab()
{
    XGCanvasQt* cvs = new XGCanvasQt;
    cvs -> updateTitle();
    addWindow(cvs);
}

void    MainWindow::cmdOpenTab(const QString& file)
{
    auto doc    = XGDocument::IO::load(std::filesystem::path(file.toStdString()));
    if(!doc){
        status(tr("Unable to load file %1").arg(file));
        return ;
    }
    
    XGCanvasQt* cvs = new XGCanvasQt;
    cvs -> set(*doc);
    addWindow(cvs);
}

void    MainWindow::cmdViewPalette()
{
    XGPaletteQt*    pal = new XGPaletteQt;
    //  we'll do stuff....
    addDock(Qt::LeftDockWidgetArea, pal);
}

XGCanvasQt*     MainWindow::currentCanvas()
{
    return dynamic_cast<XGCanvasQt*>(activeWindow());
}

MainWindow*     MainWindow::newMain() 
{
    return Tachyon::create<MainWindow>();
}

bool    MainWindow::saveTab(XGCanvasQt& cvs, const QString& fp)
{
    XGDocumentCPtr  doc = cvs.get();
    std::error_code ec = doc -> save_to(std::filesystem::path(fp.toStdString()));
    if(ec != std::error_code()){
        status(tr("Unable to save file '%1': %2").arg(fp).arg(ec.message()));
        return false;
    }
    cvs.updateTitle();
    return true;
}



#include "moc_MainWindow.cpp"
