////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetSize2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize²Command)

namespace yq::tachyon {
    SetSize²Command::SetSize²Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize²Command::SetSize²Command(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize²Command::SetSize²Command(const SetSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize²Command::~SetSize²Command()
    {
    }

    PostCPtr    SetSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetSize²Command(*this, h);
    }
    
    void SetSize²Command::init_meta()
    {
        auto w = writer<SetSize²Command>();
        w.description("Set Size Command in 2D");
        w.property("x", &SetSize²Command::x).tag(kTag_Log);
        w.property("y", &SetSize²Command::y).tag(kTag_Log);
        w.property("size", &SetSize²Command::m_size).tag(kTag_Save);
    }
}
