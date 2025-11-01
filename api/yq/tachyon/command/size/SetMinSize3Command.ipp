////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/SetMinSize3Command.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize³Command)

namespace yq::tachyon {
    SetMinSize³Command::SetMinSize³Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize³Command::SetMinSize³Command(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize³Command::SetMinSize³Command(const SetMinSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize³Command::~SetMinSize³Command()
    {
    }

    PostCPtr    SetMinSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize³Command(*this, h);
    }
    
    void SetMinSize³Command::init_meta()
    {
        auto w = writer<SetMinSize³Command>();
        w.description("SetMin Size Command in 3D");
        w.property("x", &SetMinSize³Command::x).tag(kTag_Log);
        w.property("y", &SetMinSize³Command::y).tag(kTag_Log);
        w.property("z", &SetMinSize³Command::z).tag(kTag_Log);
        w.property("size", &SetMinSize³Command::m_size).tag(kTag_Save);
    }
}
