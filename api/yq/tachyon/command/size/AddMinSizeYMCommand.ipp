////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʸDCommand)

namespace yq::tachyon {
    AddMinSizeʸDCommand::AddMinSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMinSizeʸDCommand::AddMinSizeʸDCommand(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMinSizeʸDCommand::AddMinSizeʸDCommand(const AddMinSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMinSizeʸDCommand::~AddMinSizeʸDCommand()
    {
    }

    PostCPtr    AddMinSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʸDCommand(*this, h);
    }
    
    void AddMinSizeʸDCommand::init_meta()
    {
        auto w = writer<AddMinSizeʸDCommand>();
        w.description("AddMin Size DCommand in Y");
        w.property("Δy", &AddMinSizeʸDCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
