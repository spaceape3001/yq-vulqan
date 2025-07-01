////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeˣCommand)

namespace yq::tachyon {
    AddMaxSizeˣCommand::AddMaxSizeˣCommand(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMaxSizeˣCommand::AddMaxSizeˣCommand(const AddMaxSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMaxSizeˣCommand::~AddMaxSizeˣCommand()
    {
    }
    
    PostCPtr    AddMaxSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeˣCommand(*this, h);
    }

    void AddMaxSizeˣCommand::init_info()
    {
        auto w = writer<AddMaxSizeˣCommand>();
        w.description("AddMax Size Command in X");
        w.property("Δx", &AddMaxSizeˣCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
