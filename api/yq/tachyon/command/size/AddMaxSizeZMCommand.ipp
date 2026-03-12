////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeᶻDCommand)

namespace yq::tachyon {
    AddMaxSizeᶻDCommand::AddMaxSizeᶻDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMaxSizeᶻDCommand::AddMaxSizeᶻDCommand(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMaxSizeᶻDCommand::AddMaxSizeᶻDCommand(const AddMaxSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMaxSizeᶻDCommand::~AddMaxSizeᶻDCommand()
    {
    }

    PostCPtr    AddMaxSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeᶻDCommand(*this, h);
    }
    
    void AddMaxSizeᶻDCommand::init_meta()
    {
        auto w = writer<AddMaxSizeᶻDCommand>();
        w.description("AddMax Size DCommand in Z");
        w.property("Δz", &AddMaxSizeᶻDCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
