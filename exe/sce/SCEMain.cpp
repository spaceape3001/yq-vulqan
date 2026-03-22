////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEMain.hpp"
//#include "SCEProject.hpp"
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SCEMain)

SCEMain::SCEMain()
{
    resize(1920, 1080);
    setWindowTitle(tr("Scene Editor"));
    
    activateTabs();
    enableDetachableTabs();
    enableClosableTabs();
    
    QMenu*  fileMenu    = makeMenu("file", "File");
    QMenu*  editMenu    = makeMenu("edit", "Edit");
    QMenu*  viewMenu    = makeMenu("view", "View");
    
    //  and other things....
    
    QMenu*  winMenu     = makeMenu("window", "Window");
    QMenu*  helpMenu    = makeMenu("help", "Help");
    QMenu*  dbgMenu     = makeMenu("debug", "Debug");
}

SCEMain::SCEMain(PostStartupFN&&fn) : SCEMain()
{
    m_startup   = std::move(fn);
}

SCEMain::~SCEMain()
{
}

SCEMain* SCEMain::newMain() 
{
    return Tachyon::create<SCEMain>( /* copy whatever */ );
}

Execution   SCEMain::setup(const Context&ctx) 
{
    Execution x = Tachyon::setup(ctx);
    if(is_error(x))
        return x;
        
    if(!Frame::current())
        return WAIT;

    const Frame*    frame   = Frame::current();
    //if(!frame->contains(gProjectID))
        //return WAIT;
    if(!frame->contains(id()))
        return WAIT;
        
    if(m_startup){
        m_startup(*this);
        m_startup   = {};
    }
    
    return {};
}

void SCEMain::init_meta()
{
    auto w =writer<SCEMain>();
    w.description("Scene Editor Main Window");
}


#include "moc_SCEMain.cpp"

