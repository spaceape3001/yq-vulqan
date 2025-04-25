////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSize2.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize²)

namespace yq::tachyon {
    SetMaxSize²::SetMaxSize²(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize²::SetMaxSize²(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize²::SetMaxSize²(const SetMaxSize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize²::~SetMaxSize²()
    {
    }

    PostCPtr    SetMaxSize²::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize²(*this, h);
    }
    
    void SetMaxSize²::init_info()
    {
        auto w = writer<SetMaxSize²>();
        w.description("SetMax Size Command in 2D");
        w.property("x", &SetMaxSize²::x).tag(kTag_Log);
        w.property("y", &SetMaxSize²::y).tag(kTag_Log);
        w.property("size", &SetMaxSize²::m_size).tag(kTag_Save);
    }
}
