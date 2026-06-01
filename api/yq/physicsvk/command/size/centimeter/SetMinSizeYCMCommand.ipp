////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʸCMCommand)

namespace yq::tachyon {
    SetMinSizeʸCMCommand::SetMinSizeʸCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʸCMCommand::SetMinSizeʸCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMinSizeʸCMCommand::SetMinSizeʸCMCommand(const SetMinSizeʸCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMinSizeʸCMCommand::~SetMinSizeʸCMCommand()
    {
    }

    PostCPtr    SetMinSizeʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʸCMCommand(*this, h);
    }
    
    void SetMinSizeʸCMCommand::init_meta()
    {
        auto w = writer<SetMinSizeʸCMCommand>();
        w.description("SetMin Size CMCommand in Y");
        w.property("y", &SetMinSizeʸCMCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
