////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountʷCommand)

namespace yq::tachyon {
    MultiplyCountʷCommand::MultiplyCountʷCommand(const Header&h) : 
        CountCommand(h)
    {
    }

    MultiplyCountʷCommand::MultiplyCountʷCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_δw(x)
    {
    }

    MultiplyCountʷCommand::MultiplyCountʷCommand(const MultiplyCountʷCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyCountʷCommand::~MultiplyCountʷCommand()
    {
    }
    
    PostCPtr    MultiplyCountʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountʷCommand(*this, h);
    }

    void MultiplyCountʷCommand::init_meta()
    {
        auto w = writer<MultiplyCountʷCommand>();
        w.description("Multiply Count Command");
        w.property("δw", &MultiplyCountʷCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
