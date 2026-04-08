////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MViewer.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/app/ViewerData.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MViewer)

namespace yq::tachyon {
    MViewer::MViewer(TypedID tid) : MTachyon(tid)
    {
    }
    
    MViewer::~MViewer()
    {
    }

    TypedID         MViewer::ofocus() const
    {
        const ViewerSnap* sn = osnap();
        if(!sn)
            return {};
        return sn -> focus;
    }

    ViewerID        MViewer::oid() const
    {
        if(!m_otherID(Type::Viewer))
            return {};
        return { m_otherID.id };
    }
    
    const ViewerSnap*   MViewer::osnap() const
    {
        return dynamic_cast<const ViewerSnap*>(MTachyon::osnap());
    }

    TypedID         MViewer::owidget() const
    {
        const ViewerSnap* sn = osnap();
        if(!sn)
            return {};
        return sn -> widget;
    }
    
    TypedID         MViewer::owindow() const
    {
        const ViewerSnap* sn = osnap();
        if(!sn)
            return {};
        return sn -> window;
    }
    
    void MViewer::init_meta()
    {
        auto w = writer<MViewer>();
        w.description("Viewer Qt Binder");
        w.manage<Viewer>();
    }
}


#include "moc_MViewer.cpp"
