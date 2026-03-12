////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʷDCommand)

namespace yq::tachyon {
    AddMinSizeʷDCommand::AddMinSizeʷDCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMinSizeʷDCommand::AddMinSizeʷDCommand(const AddMinSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMinSizeʷDCommand::~AddMinSizeʷDCommand()
    {
    }
    
    PostCPtr    AddMinSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʷDCommand(*this, h);
    }

    void AddMinSizeʷDCommand::init_meta()
    {
        auto w = writer<AddMinSizeʷDCommand>();
        w.description("AddMin Size DCommand in X");
        w.property("Δw", &AddMinSizeʷDCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
