////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMinSizeX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeˣ)

namespace yq::tachyon {
    SetMinSizeˣ::SetMinSizeˣ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMinSizeˣ::SetMinSizeˣ(const Header& h, double v) : 
        SpatialCommand(h), m_x(v)
    {
    }

    SetMinSizeˣ::SetMinSizeˣ(const SetMinSizeˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMinSizeˣ::~SetMinSizeˣ()
    {
    }

    PostCPtr    SetMinSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeˣ(*this, h);
    }
    
    void SetMinSizeˣ::init_info()
    {
        auto w = writer<SetMinSizeˣ>();
        w.description("SetMin Size Command in X");
        w.property("x", &SetMinSizeˣ::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
