////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSize3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize³Command)

namespace yq::tachyon {
    SetMaxSize³Command::SetMaxSize³Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize³Command::SetMaxSize³Command(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize³Command::SetMaxSize³Command(const SetMaxSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize³Command::~SetMaxSize³Command()
    {
    }

    PostCPtr    SetMaxSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize³Command(*this, h);
    }
    
    void SetMaxSize³Command::init_info()
    {
        auto w = writer<SetMaxSize³Command>();
        w.description("SetMax Size Command in 3D");
        w.property("x", &SetMaxSize³Command::x).tag(kTag_Log);
        w.property("y", &SetMaxSize³Command::y).tag(kTag_Log);
        w.property("z", &SetMaxSize³Command::z).tag(kTag_Log);
        w.property("size", &SetMaxSize³Command::m_size).tag(kTag_Save);
    }
}
