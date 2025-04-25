////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSize1.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize¹)

namespace yq::tachyon {
    SetMaxSize¹::SetMaxSize¹(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize¹::SetMaxSize¹(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize¹::SetMaxSize¹(const SetMaxSize¹& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize¹::~SetMaxSize¹()
    {
    }

    PostCPtr    SetMaxSize¹::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize¹(*this, h);
    }
    
    void SetMaxSize¹::init_info()
    {
        auto w = writer<SetMaxSize¹>();
        w.description("SetMax Size Command in 1D");
        w.property("x", &SetMaxSize¹::x).tag(kTag_Log);
        w.property("size", &SetMaxSize¹::m_size).tag(kTag_Save);
    }
}
