////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMinSize2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize²)

namespace yq::tachyon {
    SetMinSize²::SetMinSize²(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMinSize²::SetMinSize²(const Header& h, const Size2D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetMinSize²::SetMinSize²(const SetMinSize²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize²::~SetMinSize²()
    {
    }

    PostCPtr    SetMinSize²::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize²(*this, h);
    }
    
    void SetMinSize²::init_info()
    {
        auto w = writer<SetMinSize²>();
        w.description("SetMin Size Command in 2D");
        w.property("x", &SetMinSize²::x).tag(kTag_Log);
        w.property("y", &SetMinSize²::y).tag(kTag_Log);
        w.property("size", &SetMinSize²::m_size).tag(kTag_Save);
    }
}
