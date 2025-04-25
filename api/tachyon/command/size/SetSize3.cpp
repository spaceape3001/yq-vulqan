////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetSize3.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize³)

namespace yq::tachyon {
    SetSize³::SetSize³(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize³::SetSize³(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize³::SetSize³(const SetSize³& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize³::~SetSize³()
    {
    }

    PostCPtr    SetSize³::clone(rebind_k, const Header&h) const 
    {
        return new SetSize³(*this, h);
    }
    
    void SetSize³::init_info()
    {
        auto w = writer<SetSize³>();
        w.description("Set Size Command in 3D");
        w.property("x", &SetSize³::x).tag(kTag_Log);
        w.property("y", &SetSize³::y).tag(kTag_Log);
        w.property("z", &SetSize³::z).tag(kTag_Log);
        w.property("size", &SetSize³::m_size).tag(kTag_Save);
    }
}
