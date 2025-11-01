////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/SetSize1Command.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize¹Command)

namespace yq::tachyon {
    SetSize¹Command::SetSize¹Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize¹Command::SetSize¹Command(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize¹Command::SetSize¹Command(const SetSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize¹Command::~SetSize¹Command()
    {
    }

    PostCPtr    SetSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetSize¹Command(*this, h);
    }
    
    void SetSize¹Command::init_meta()
    {
        auto w = writer<SetSize¹Command>();
        w.description("Set Size Command in 1D");
        w.property("x", &SetSize¹Command::x).tag(kTag_Log);
        w.property("size", &SetSize¹Command::m_size).tag(kTag_Save);
    }
}
