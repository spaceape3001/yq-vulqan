////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʸCommand)

namespace yq::tachyon {
    AddMaxSizeʸCommand::AddMaxSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMaxSizeʸCommand::AddMaxSizeʸCommand(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMaxSizeʸCommand::AddMaxSizeʸCommand(const AddMaxSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMaxSizeʸCommand::~AddMaxSizeʸCommand()
    {
    }

    PostCPtr    AddMaxSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʸCommand(*this, h);
    }
    
    void AddMaxSizeʸCommand::init_info()
    {
        auto w = writer<AddMaxSizeʸCommand>();
        w.description("AddMax Size Command in Y");
        w.property("Δy", &AddMaxSizeʸCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
