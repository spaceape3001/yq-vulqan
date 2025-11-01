////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/widget/SetViewer.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetViewer)

namespace yq::tachyon {
    SetViewer::SetViewer(const Header& h, TypedID vid) : WidgetCommand(h), m_viewer(vid)
    {
    }

    SetViewer::SetViewer(const SetViewer& cp, const Header& h) : WidgetCommand(cp, h), m_viewer(cp.m_viewer)
    {
    }

    SetViewer::~SetViewer()
    {
    }
    
    PostCPtr    SetViewer::clone(rebind_k, const Header&h) const
    {
        return new SetViewer(*this, h);
    }

    void SetViewer::init_meta()
    {
        auto w = writer<SetViewer>();
        w.description("Set Viewer Command");
    }
}
