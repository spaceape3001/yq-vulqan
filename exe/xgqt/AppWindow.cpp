////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppWindow.hpp"
#include <yq/core/Logging.hpp>
#include <yq/graph/GBaseData.hpp>
#include <yq/graph/GDocument.hpp>
#include <yq/graph/GMetaGraph.hpp>
#include <yq/graphQt/GNodePalette.hpp>
#include <yq/graphQt/GraphCanvas.hpp>
#include <yq/graphQt/GraphScene.hpp>
#include <yq/graphicsQt/GraphicsToolBar.hpp>
#include <yq/vkqt/app/YMainMetaWriter.hpp>
#include <yq/xg/XGElement.hpp>
//#include <yq/xg/XGXmlIO.hpp>

#include <QAction>
#include <QCursor>
#include <QFileDialog>
#include <QMenu>
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
    addAction("save", "Save").shortcut("Ctrl+S").connect(this, &AppWindow::cmdFileSave);
    addAction("saveas", "Save As").connect(this, &AppWindow::cmdFileSaveAs);
    addAction("selectAll", "Select All").shortcut("Ctrl+A").connect(this, &AppWindow::cmdSelectAll);
    addAction("selectNone", "Clear Selection").shortcut("Shift+Ctrl+A").connect(this, &AppWindow::cmdSelectNone);
    addAction("palette", "Palette").connect(this, &AppWindow::cmdViewPalette);
    addAction("print", "Print").shortcut("Ctrl+P").connect(this, &AppWindow::cmdFilePrint);
    addAction("properties", "Properties...").connect(this, &AppWindow::cmdEditProperties);

    makeMenu("file", "File", QStringList() << "new" << "open" << "save" << "saveas" << "print" );
    makeMenu("edit", "Edit", QStringList() << "undo" << "redo" << "selectAll" << "selectNone");
    makeMenu("view", "View", QStringList() << "palette");
    
    m_docPopup      = new QMenu(this);
    m_basePopup     = new QMenu(this);
    m_edgePopup     = new QMenu(this);
    m_graphPopup    = new QMenu(this);
    m_linePopup     = new QMenu(this);
    m_nodePopup     = new QMenu(this);
    m_portPopup     = new QMenu(this);
    m_textPopup     = new QMenu(this);
    m_shapePopup    = new QMenu(this);
    
    //  debugging...
    m_docPopup->addAction(new QAction("Document"));
    m_docPopup->addSeparator();
    
    m_basePopup->addAction(new QAction("Base"));
    m_basePopup->addSeparator();

    m_edgePopup->addAction(new QAction("Edge"));
    m_edgePopup->addSeparator();

    m_graphPopup->addAction(new QAction("Graph"));
    m_graphPopup->addSeparator();

    m_nodePopup->addAction(new QAction("Node"));
    m_nodePopup->addSeparator();

    m_portPopup->addAction(new QAction("Port"));
    m_portPopup->addSeparator();

    m_shapePopup->addAction(new QAction("Shape"));
    m_shapePopup->addSeparator();

    m_textPopup->addAction(new QAction("Text"));
    m_textPopup->addSeparator();
    
    addToMenu(m_basePopup, { "properties" });
    addToMenu(m_docPopup, { "properties" });
    addToMenu(m_edgePopup, { "properties" });
    addToMenu(m_graphPopup, { "properties" });
    addToMenu(m_linePopup, { "properties" });
    addToMenu(m_nodePopup, { "properties" });
    addToMenu(m_portPopup, { "properties" });
    addToMenu(m_shapePopup, { "properties" });
    addToMenu(m_textPopup, { "properties" });
    
    m_toolbar   = new GraphicsToolBar;
    connect(m_toolbar, &GraphicsToolBar::clicked, this, &AppWindow::cmdToolChange);
    
    // TODO... text file configurable
    m_toolbar -> add(TOOL, "gluon::SuperGraphTool");
    //m_toolbar -> add(TOOL, "gluon::SelectTool");
    //m_toolbar -> add(TOOL, "gluon::PanTool");
    //m_toolbar -> add(TOOL, "gluon::MoveTool");
    m_toolbar -> add(TOOL, "gluon::EdgeConnectorTool");
    m_toolbar -> add(TOOL, "gluon::GraphLineTool");
    m_toolbar -> add(TOOL, "gluon::GraphTextTool");
    
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

void    AppWindow::cmdEditProperties()
{
    
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
        this, tr("Open Graph File"), dir,
        "Graph Files (*.g)"
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
        this, tr("Save Graph File"), cvs->dirname(),
        "Graph Files (*.g)"
    );
    if(file.isEmpty())
        return;
    saveTab(*cvs, file);
}

void    AppWindow::cmdNewTab()
{
    GGraph      graph(CREATE);
    graph.document()->kind(SET, "executive");
    createTab(graph, {});
    
}

void    AppWindow::cmdOpenTab(const QString& file)
{
    auto doc    = GDocument::IO::load(std::filesystem::path(file.toStdString()));
    if(!doc){
        status(tr("Unable to load file %1").arg(file));
        return ;
    }
    
    createTab(doc->clone(), doc->url());
}

void    AppWindow::cmdSelectAll()
{
    GraphCanvas*     cvs = currentCanvas();
    if(!cvs)
        return ;
    cvs -> selectAll();
}

void    AppWindow::cmdSelectNone()
{
    GraphCanvas*     cvs = currentCanvas();
    if(!cvs)
        return ;
    cvs -> selectNone();
}


void    AppWindow::cmdToolChange(uint64_t i)
{
yInfo() << "cmdToolChange(" << i << ")";
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

void    AppWindow::createTab(GGraph g, const Url&u)
{
    GraphCanvas* cvs = new GraphCanvas;
    cvs -> set(g,u);
    cvs -> updateTitle();
    cvs -> setTool( m_toolbar->tools().front() );
    connect(cvs, &GraphCanvas::contextRequest, this, &AppWindow::ctxCanvas);
    addWindow(cvs);
}

void    AppWindow::ctxCanvas(uint64_t id)
{
    m_dataId    = id;

    QMenu*      pMenu   = m_docPopup;
    
    GraphCanvas* cvs = currentCanvas(); 
    if(id && cvs && cvs->document()){
        if(const GBaseData* gb = cvs->document()->data(m_dataId)){
            if(gb->is_edge()){
                pMenu   = m_edgePopup;
            } else if(gb->is_graph()){
                pMenu   = m_graphPopup;
            } else if(gb->is_line()){
                pMenu   = m_linePopup;
            } else if(gb->is_node()){
                pMenu   = m_nodePopup;
            } else if(gb->is_port()){
                pMenu   = m_portPopup;
            } else if(gb->is_shape()){
                pMenu   = m_shapePopup;
            } else if(gb->is_text()){
                pMenu   = m_textPopup;
            }
        }
    }

    pMenu -> exec(QCursor::pos());
    if(cvs)
        cvs -> focusMe();
}

GraphCanvas*     AppWindow::currentCanvas()
{
    return dynamic_cast<GraphCanvas*>(activeWindow());
}

void    AppWindow::dblClick(uint64_t id)
{
    m_dataId    = id;
}

AppWindow*     AppWindow::newMain() 
{
    return Tachyon::create<AppWindow>();
}

bool    AppWindow::saveTab(GraphCanvas& cvs, const QString& fp)
{
    GDocumentCPtr  doc = cvs.document();
    if(!doc){
        status(tr("Unable to save file '%1': NO DOCUMENT").arg(fp));
        return false;
    }
    
    std::error_code ec = doc -> save_to(std::filesystem::path(fp.toStdString()),
        { .collision = FileCollisionStrategy::Backup }
    );
    if(ec != std::error_code()){
        status(tr("Unable to save file '%1': %2").arg(fp).arg(ec.message()));
        return false;
    }
    cvs.updateTitle();
    return true;
}



#include "moc_AppWindow.cpp"
