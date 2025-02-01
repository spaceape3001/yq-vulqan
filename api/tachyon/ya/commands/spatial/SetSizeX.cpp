////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetSizeX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeˣ)

namespace yq::tachyon {
    SetSizeˣ::SetSizeˣ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetSizeˣ::SetSizeˣ(const Header& h, double v) : 
        SpatialCommand(h), m_x(v)
    {
    }

    SetSizeˣ::SetSizeˣ(const SetSizeˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetSizeˣ::~SetSizeˣ()
    {
    }

    PostCPtr    SetSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeˣ(*this, h);
    }
    
    void SetSizeˣ::init_info()
    {
        auto w = writer<SetSizeˣ>();
        w.description("Set Size Command in X");
        w.property("x", &SetSizeˣ::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
