////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeᶻCommand)

namespace yq::tachyon {
    AddMaxSizeᶻCommand::AddMaxSizeᶻCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMaxSizeᶻCommand::AddMaxSizeᶻCommand(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMaxSizeᶻCommand::AddMaxSizeᶻCommand(const AddMaxSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMaxSizeᶻCommand::~AddMaxSizeᶻCommand()
    {
    }

    PostCPtr    AddMaxSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeᶻCommand(*this, h);
    }
    
    void AddMaxSizeᶻCommand::init_info()
    {
        auto w = writer<AddMaxSizeᶻCommand>();
        w.description("AddMax Size Command in Z");
        w.property("Δz", &AddMaxSizeᶻCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
