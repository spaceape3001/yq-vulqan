////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSizeX.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeˣ)

namespace yq::tachyon {
    SetMinSizeˣ::SetMinSizeˣ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeˣ::SetMinSizeˣ(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMinSizeˣ::SetMinSizeˣ(const SetMinSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
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
