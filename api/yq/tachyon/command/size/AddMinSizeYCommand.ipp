////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSizeYCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʸCommand)

namespace yq::tachyon {
    AddMinSizeʸCommand::AddMinSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMinSizeʸCommand::AddMinSizeʸCommand(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMinSizeʸCommand::AddMinSizeʸCommand(const AddMinSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMinSizeʸCommand::~AddMinSizeʸCommand()
    {
    }

    PostCPtr    AddMinSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʸCommand(*this, h);
    }
    
    void AddMinSizeʸCommand::init_meta()
    {
        auto w = writer<AddMinSizeʸCommand>();
        w.description("AddMin Size Command in Y");
        w.property("Δy", &AddMinSizeʸCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
