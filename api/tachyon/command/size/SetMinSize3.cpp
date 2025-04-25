////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSize3.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize³)

namespace yq::tachyon {
    SetMinSize³::SetMinSize³(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize³::SetMinSize³(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize³::SetMinSize³(const SetMinSize³& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize³::~SetMinSize³()
    {
    }

    PostCPtr    SetMinSize³::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize³(*this, h);
    }
    
    void SetMinSize³::init_info()
    {
        auto w = writer<SetMinSize³>();
        w.description("SetMin Size Command in 3D");
        w.property("x", &SetMinSize³::x).tag(kTag_Log);
        w.property("y", &SetMinSize³::y).tag(kTag_Log);
        w.property("z", &SetMinSize³::z).tag(kTag_Log);
        w.property("size", &SetMinSize³::m_size).tag(kTag_Save);
    }
}
