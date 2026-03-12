////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʷDCommand)

namespace yq::tachyon {
    SetMinSizeʷDCommand::SetMinSizeʷDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʷDCommand::SetMinSizeʷDCommand(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMinSizeʷDCommand::SetMinSizeʷDCommand(const SetMinSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMinSizeʷDCommand::~SetMinSizeʷDCommand()
    {
    }

    PostCPtr    SetMinSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʷDCommand(*this, h);
    }
    
    void SetMinSizeʷDCommand::init_meta()
    {
        auto w = writer<SetMinSizeʷDCommand>();
        w.description("SetMin Size DCommand in X");
        w.property("w", &SetMinSizeʷDCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
