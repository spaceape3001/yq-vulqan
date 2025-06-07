////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSizeWCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʷCommand)

namespace yq::tachyon {
    AddMinSizeʷCommand::AddMinSizeʷCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMinSizeʷCommand::AddMinSizeʷCommand(const AddMinSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMinSizeʷCommand::~AddMinSizeʷCommand()
    {
    }
    
    PostCPtr    AddMinSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʷCommand(*this, h);
    }

    void AddMinSizeʷCommand::init_info()
    {
        auto w = writer<AddMinSizeʷCommand>();
        w.description("AddMin Size Command in X");
        w.property("Δw", &AddMinSizeʷCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
