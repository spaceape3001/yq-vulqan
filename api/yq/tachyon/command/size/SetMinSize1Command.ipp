////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize¹DCommand)

namespace yq::tachyon {
    SetMinSize¹DCommand::SetMinSize¹DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize¹DCommand::SetMinSize¹DCommand(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize¹DCommand::SetMinSize¹DCommand(const SetMinSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize¹DCommand::~SetMinSize¹DCommand()
    {
    }

    PostCPtr    SetMinSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize¹DCommand(*this, h);
    }
    
    void SetMinSize¹DCommand::init_meta()
    {
        auto w = writer<SetMinSize¹DCommand>();
        w.description("SetMin Size DCommand in 1D");
        w.property("x", &SetMinSize¹DCommand::x).tag(kTag_Log);
        w.property("size", &SetMinSize¹DCommand::m_size).tag(kTag_Save);
    }
}
