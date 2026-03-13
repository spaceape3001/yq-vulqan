////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountZUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountᶻUCommand)

namespace yq::tachyon {
    MultiplyCountᶻUCommand::MultiplyCountᶻUCommand(const Header&h) : 
        CountCommand(h)
    {
    }
    
    MultiplyCountᶻUCommand::MultiplyCountᶻUCommand(const Header&h, unsigned z) : 
        CountCommand(h), m_δz(z)
    {
    }
    
    MultiplyCountᶻUCommand::MultiplyCountᶻUCommand(const MultiplyCountᶻUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyCountᶻUCommand::~MultiplyCountᶻUCommand()
    {
    }

    PostCPtr    MultiplyCountᶻUCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountᶻUCommand(*this, h);
    }
    
    void MultiplyCountᶻUCommand::init_meta()
    {
        auto w = writer<MultiplyCountᶻUCommand>();
        w.description("Multiply Count Command");
        w.property("δz", &MultiplyCountᶻUCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
