////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountᶻCommand)

namespace yq::tachyon {
    MultiplyCountᶻCommand::MultiplyCountᶻCommand(const Header&h) : 
        CountCommand(h)
    {
    }
    
    MultiplyCountᶻCommand::MultiplyCountᶻCommand(const Header&h, unsigned z) : 
        CountCommand(h), m_δz(z)
    {
    }
    
    MultiplyCountᶻCommand::MultiplyCountᶻCommand(const MultiplyCountᶻCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyCountᶻCommand::~MultiplyCountᶻCommand()
    {
    }

    PostCPtr    MultiplyCountᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountᶻCommand(*this, h);
    }
    
    void MultiplyCountᶻCommand::init_meta()
    {
        auto w = writer<MultiplyCountᶻCommand>();
        w.description("Multiply Count Command");
        w.property("δz", &MultiplyCountᶻCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
