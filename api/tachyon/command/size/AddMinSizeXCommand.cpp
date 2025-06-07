////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSizeXCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeˣCommand)

namespace yq::tachyon {
    AddMinSizeˣCommand::AddMinSizeˣCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMinSizeˣCommand::AddMinSizeˣCommand(const AddMinSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMinSizeˣCommand::~AddMinSizeˣCommand()
    {
    }
    
    PostCPtr    AddMinSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeˣCommand(*this, h);
    }

    void AddMinSizeˣCommand::init_info()
    {
        auto w = writer<AddMinSizeˣCommand>();
        w.description("AddMin Size Command in X");
        w.property("Δx", &AddMinSizeˣCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
