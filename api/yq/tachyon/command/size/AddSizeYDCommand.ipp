////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʸDCommand)

namespace yq::tachyon {
    AddSizeʸDCommand::AddSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddSizeʸDCommand::AddSizeʸDCommand(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddSizeʸDCommand::AddSizeʸDCommand(const AddSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddSizeʸDCommand::~AddSizeʸDCommand()
    {
    }

    PostCPtr    AddSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʸDCommand(*this, h);
    }
    
    void AddSizeʸDCommand::init_meta()
    {
        auto w = writer<AddSizeʸDCommand>();
        w.description("Add Size DCommand in Y");
        w.property("Δy", &AddSizeʸDCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
