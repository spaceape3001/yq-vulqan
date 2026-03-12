////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʷDCommand)

namespace yq::tachyon {
    AddMaxSizeʷDCommand::AddMaxSizeʷDCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMaxSizeʷDCommand::AddMaxSizeʷDCommand(const AddMaxSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMaxSizeʷDCommand::~AddMaxSizeʷDCommand()
    {
    }
    
    PostCPtr    AddMaxSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʷDCommand(*this, h);
    }

    void AddMaxSizeʷDCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʷDCommand>();
        w.description("AddMax Size DCommand in X");
        w.property("Δw", &AddMaxSizeʷDCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
