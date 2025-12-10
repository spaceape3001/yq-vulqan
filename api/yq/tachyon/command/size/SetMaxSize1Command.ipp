////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize¹Command)

namespace yq::tachyon {
    SetMaxSize¹Command::SetMaxSize¹Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize¹Command::SetMaxSize¹Command(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize¹Command::SetMaxSize¹Command(const SetMaxSize¹Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize¹Command::~SetMaxSize¹Command()
    {
    }

    PostCPtr    SetMaxSize¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize¹Command(*this, h);
    }
    
    void SetMaxSize¹Command::init_meta()
    {
        auto w = writer<SetMaxSize¹Command>();
        w.description("SetMax Size Command in 1D");
        w.property("x", &SetMaxSize¹Command::x).tag(kTag_Log);
        w.property("size", &SetMaxSize¹Command::m_size).tag(kTag_Save);
    }
}
