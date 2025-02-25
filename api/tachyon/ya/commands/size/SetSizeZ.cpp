////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetSizeZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeᶻ)

namespace yq::tachyon {
    SetSizeᶻ::SetSizeᶻ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeᶻ::SetSizeᶻ(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetSizeᶻ::SetSizeᶻ(const SetSizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetSizeᶻ::~SetSizeᶻ()
    {
    }

    PostCPtr    SetSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeᶻ(*this, h);
    }
    
    void SetSizeᶻ::init_info()
    {
        auto w = writer<SetSizeᶻ>();
        w.description("Set Size Command in Z");
        w.property("z", &SetSizeᶻ::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
