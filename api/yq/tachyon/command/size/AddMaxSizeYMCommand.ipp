////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʸDCommand)

namespace yq::tachyon {
    AddMaxSizeʸDCommand::AddMaxSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMaxSizeʸDCommand::AddMaxSizeʸDCommand(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMaxSizeʸDCommand::AddMaxSizeʸDCommand(const AddMaxSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMaxSizeʸDCommand::~AddMaxSizeʸDCommand()
    {
    }

    PostCPtr    AddMaxSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʸDCommand(*this, h);
    }
    
    void AddMaxSizeʸDCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʸDCommand>();
        w.description("AddMax Size DCommand in Y");
        w.property("Δy", &AddMaxSizeʸDCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
