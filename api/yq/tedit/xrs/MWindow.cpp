////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MWindow.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/os/Window.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MWindow)

namespace yq::tachyon {
    MWindow::MWindow(TypedID tid) : MTachyon(tid)
    {
    }
    
    MWindow::~MWindow()
    {
    }
    
    WindowID     MWindow::oid() const
    {
        if(!m_otherID(Type::Window))
            return {};
        return { m_otherID.id };
    }

    void MWindow::init_meta()
    {
        auto w = writer<MWindow>();
        w.description("Window Qt Binder");
        w.manage<Window>();
    }
}


#include "moc_MWindow.cpp"
