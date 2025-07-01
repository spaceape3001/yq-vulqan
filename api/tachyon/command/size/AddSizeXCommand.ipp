////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeˣCommand)

namespace yq::tachyon {
    AddSizeˣCommand::AddSizeˣCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddSizeˣCommand::AddSizeˣCommand(const AddSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddSizeˣCommand::~AddSizeˣCommand()
    {
    }
    
    PostCPtr    AddSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeˣCommand(*this, h);
    }

    void AddSizeˣCommand::init_info()
    {
        auto w = writer<AddSizeˣCommand>();
        w.description("Add Size Command in X");
        w.property("Δx", &AddSizeˣCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
