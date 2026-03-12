////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʷDCommand)

namespace yq::tachyon {
    AddSizeʷDCommand::AddSizeʷDCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddSizeʷDCommand::AddSizeʷDCommand(const AddSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddSizeʷDCommand::~AddSizeʷDCommand()
    {
    }
    
    PostCPtr    AddSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʷDCommand(*this, h);
    }

    void AddSizeʷDCommand::init_meta()
    {
        auto w = writer<AddSizeʷDCommand>();
        w.description("Add Size DCommand in X");
        w.property("Δw", &AddSizeʷDCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
