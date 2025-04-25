////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetMaxSizeX.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeˣ)

namespace yq::tachyon {
    SetMaxSizeˣ::SetMaxSizeˣ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeˣ::SetMaxSizeˣ(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMaxSizeˣ::SetMaxSizeˣ(const SetMaxSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMaxSizeˣ::~SetMaxSizeˣ()
    {
    }

    PostCPtr    SetMaxSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeˣ(*this, h);
    }
    
    void SetMaxSizeˣ::init_info()
    {
        auto w = writer<SetMaxSizeˣ>();
        w.description("SetMax Size Command in X");
        w.property("x", &SetMaxSizeˣ::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
