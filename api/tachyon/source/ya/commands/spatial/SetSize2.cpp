////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetSize2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize²)

namespace yq::tachyon {
    SetSize²::SetSize²(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetSize²::SetSize²(const Header& h, const Size2D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetSize²::SetSize²(const SetSize²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize²::~SetSize²()
    {
    }

    PostCPtr    SetSize²::clone(rebind_k, const Header&h) const 
    {
        return new SetSize²(*this, h);
    }
    
    void SetSize²::init_info()
    {
        auto w = writer<SetSize²>();
        w.description("Set Size Command in 2D");
        w.property("x", &SetSize²::x).tag(kTag_Log);
        w.property("y", &SetSize²::y).tag(kTag_Log);
        w.property("size", &SetSize²::m_size).tag(kTag_Save);
    }
}
