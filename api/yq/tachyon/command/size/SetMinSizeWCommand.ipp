////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSizeWCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʷCommand)

namespace yq::tachyon {
    SetMinSizeʷCommand::SetMinSizeʷCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʷCommand::SetMinSizeʷCommand(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMinSizeʷCommand::SetMinSizeʷCommand(const SetMinSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMinSizeʷCommand::~SetMinSizeʷCommand()
    {
    }

    PostCPtr    SetMinSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʷCommand(*this, h);
    }
    
    void SetMinSizeʷCommand::init_meta()
    {
        auto w = writer<SetMinSizeʷCommand>();
        w.description("SetMin Size Command in X");
        w.property("w", &SetMinSizeʷCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
