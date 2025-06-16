////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSize2Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize²Command)

namespace yq::tachyon {
    SetMinSize²Command::SetMinSize²Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize²Command::SetMinSize²Command(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize²Command::SetMinSize²Command(const SetMinSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize²Command::~SetMinSize²Command()
    {
    }

    PostCPtr    SetMinSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize²Command(*this, h);
    }
    
    void SetMinSize²Command::init_info()
    {
        auto w = writer<SetMinSize²Command>();
        w.description("SetMin Size Command in 2D");
        w.property("x", &SetMinSize²Command::x).tag(kTag_Log);
        w.property("y", &SetMinSize²Command::y).tag(kTag_Log);
        w.property("size", &SetMinSize²Command::m_size).tag(kTag_Save);
    }
}
