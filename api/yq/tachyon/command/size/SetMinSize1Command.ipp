////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSize1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize¹Command)

namespace yq::tachyon {
    SetMinSize¹Command::SetMinSize¹Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize¹Command::SetMinSize¹Command(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize¹Command::SetMinSize¹Command(const SetMinSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize¹Command::~SetMinSize¹Command()
    {
    }

    PostCPtr    SetMinSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize¹Command(*this, h);
    }
    
    void SetMinSize¹Command::init_meta()
    {
        auto w = writer<SetMinSize¹Command>();
        w.description("SetMin Size Command in 1D");
        w.property("x", &SetMinSize¹Command::x).tag(kTag_Log);
        w.property("size", &SetMinSize¹Command::m_size).tag(kTag_Save);
    }
}
