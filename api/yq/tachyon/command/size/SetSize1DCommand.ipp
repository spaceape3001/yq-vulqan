////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize¹DCommand)

namespace yq::tachyon {
    SetSize¹DCommand::SetSize¹DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize¹DCommand::SetSize¹DCommand(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize¹DCommand::SetSize¹DCommand(const SetSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize¹DCommand::~SetSize¹DCommand()
    {
    }

    PostCPtr    SetSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize¹DCommand(*this, h);
    }
    
    void SetSize¹DCommand::init_meta()
    {
        auto w = writer<SetSize¹DCommand>();
        w.description("Set Size DCommand in 1D");
        w.property("x", &SetSize¹DCommand::x).tag(kTag_Log);
        w.property("size", &SetSize¹DCommand::m_size).tag(kTag_Save);
    }
}
