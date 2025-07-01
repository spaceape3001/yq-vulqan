////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSizeZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeᶻCommand)

namespace yq::tachyon {
    AddSizeᶻCommand::AddSizeᶻCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddSizeᶻCommand::AddSizeᶻCommand(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddSizeᶻCommand::AddSizeᶻCommand(const AddSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddSizeᶻCommand::~AddSizeᶻCommand()
    {
    }

    PostCPtr    AddSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeᶻCommand(*this, h);
    }
    
    void AddSizeᶻCommand::init_info()
    {
        auto w = writer<AddSizeᶻCommand>();
        w.description("Add Size Command in Z");
        w.property("Δz", &AddSizeᶻCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
