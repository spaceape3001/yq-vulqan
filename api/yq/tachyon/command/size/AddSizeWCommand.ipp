////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/AddSizeWCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʷCommand)

namespace yq::tachyon {
    AddSizeʷCommand::AddSizeʷCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddSizeʷCommand::AddSizeʷCommand(const AddSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddSizeʷCommand::~AddSizeʷCommand()
    {
    }
    
    PostCPtr    AddSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʷCommand(*this, h);
    }

    void AddSizeʷCommand::init_meta()
    {
        auto w = writer<AddSizeʷCommand>();
        w.description("Add Size Command in X");
        w.property("Δw", &AddSizeʷCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
