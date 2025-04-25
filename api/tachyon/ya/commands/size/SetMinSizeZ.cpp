////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetMinSizeZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeᶻ)

namespace yq::tachyon {
    SetMinSizeᶻ::SetMinSizeᶻ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeᶻ::SetMinSizeᶻ(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMinSizeᶻ::SetMinSizeᶻ(const SetMinSizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMinSizeᶻ::~SetMinSizeᶻ()
    {
    }

    PostCPtr    SetMinSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeᶻ(*this, h);
    }
    
    void SetMinSizeᶻ::init_info()
    {
        auto w = writer<SetMinSizeᶻ>();
        w.description("SetMin Size Command in Z");
        w.property("z", &SetMinSizeᶻ::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
