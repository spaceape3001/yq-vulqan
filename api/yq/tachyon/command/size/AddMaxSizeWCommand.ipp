////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/AddMaxSizeWCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʷCommand)

namespace yq::tachyon {
    AddMaxSizeʷCommand::AddMaxSizeʷCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMaxSizeʷCommand::AddMaxSizeʷCommand(const AddMaxSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMaxSizeʷCommand::~AddMaxSizeʷCommand()
    {
    }
    
    PostCPtr    AddMaxSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʷCommand(*this, h);
    }

    void AddMaxSizeʷCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʷCommand>();
        w.description("AddMax Size Command in X");
        w.property("Δw", &AddMaxSizeʷCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
