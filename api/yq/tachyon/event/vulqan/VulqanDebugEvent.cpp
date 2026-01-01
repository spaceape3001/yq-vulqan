////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanDebugEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/vulkan/ViDebugTrace.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VulqanDebugEvent)

namespace yq::tachyon {

    VulqanDebugEvent::VulqanDebugEvent(const Header&h, const ViDebugTraceCPtr& vt) : VulqanEvent(h), m_trace(vt)
    {
    }

    VulqanDebugEvent::VulqanDebugEvent(const VulqanDebugEvent& cp, const Header& h) : 
        VulqanEvent(cp, h), m_trace(cp.m_trace)
    {
    }
    
    VulqanDebugEvent::~VulqanDebugEvent()
    {
    }

    PostCPtr    VulqanDebugEvent::clone(rebind_k, const Header&h) const 
    {
        return new VulqanDebugEvent(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void VulqanDebugEvent::init_meta()
    {
        auto w = writer<VulqanDebugEvent>();
        w.description("Vulqan Debug (Trace) Event");
    }
}
