////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize¹DCommand)

namespace yq::tachyon {
    SetMaxSize¹DCommand::SetMaxSize¹DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize¹DCommand::SetMaxSize¹DCommand(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize¹DCommand::SetMaxSize¹DCommand(const SetMaxSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize¹DCommand::~SetMaxSize¹DCommand()
    {
    }

    PostCPtr    SetMaxSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize¹DCommand(*this, h);
    }
    
    void SetMaxSize¹DCommand::init_meta()
    {
        auto w = writer<SetMaxSize¹DCommand>();
        w.description("SetMax Size DCommand in 1D");
        w.property("x", &SetMaxSize¹DCommand::x).tag(kTag_Log);
        w.property("size", &SetMaxSize¹DCommand::m_size).tag(kTag_Save);
    }
}
