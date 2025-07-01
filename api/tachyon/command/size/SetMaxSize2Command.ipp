////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSize2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize²Command)

namespace yq::tachyon {
    SetMaxSize²Command::SetMaxSize²Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize²Command::SetMaxSize²Command(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize²Command::SetMaxSize²Command(const SetMaxSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize²Command::~SetMaxSize²Command()
    {
    }

    PostCPtr    SetMaxSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize²Command(*this, h);
    }
    
    void SetMaxSize²Command::init_info()
    {
        auto w = writer<SetMaxSize²Command>();
        w.description("SetMax Size Command in 2D");
        w.property("x", &SetMaxSize²Command::x).tag(kTag_Log);
        w.property("y", &SetMaxSize²Command::y).tag(kTag_Log);
        w.property("size", &SetMaxSize²Command::m_size).tag(kTag_Save);
    }
}
