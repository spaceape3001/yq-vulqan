////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEMain.hpp"
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SCEMain)

SCEMain::SCEMain()
{
    resize(1920, 1080);
    setWindowTitle(tr("Scene Editor"));
    show();
}

SCEMain::~SCEMain()
{
}

void SCEMain::init_meta()
{
    auto w =writer<SCEMain>();
    w.description("Scene Editor Main Window");
}


#include "moc_SCEMain.cpp"

