////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetMinSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize¹)

namespace yq::tachyon {
    SetMinSize¹::SetMinSize¹(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize¹::SetMinSize¹(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize¹::SetMinSize¹(const SetMinSize¹& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize¹::~SetMinSize¹()
    {
    }

    PostCPtr    SetMinSize¹::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize¹(*this, h);
    }
    
    void SetMinSize¹::init_info()
    {
        auto w = writer<SetMinSize¹>();
        w.description("SetMin Size Command in 1D");
        w.property("x", &SetMinSize¹::x).tag(kTag_Log);
        w.property("size", &SetMinSize¹::m_size).tag(kTag_Save);
    }
}
