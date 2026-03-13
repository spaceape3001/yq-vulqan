////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountXCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountˣCommand)

namespace yq::tachyon {
    MultiplyCountˣCommand::MultiplyCountˣCommand(const Header&h) : 
        CountCommand(h)
    {
    }

    MultiplyCountˣCommand::MultiplyCountˣCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_δx(x)
    {
    }

    MultiplyCountˣCommand::MultiplyCountˣCommand(const MultiplyCountˣCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyCountˣCommand::~MultiplyCountˣCommand()
    {
    }
    
    PostCPtr    MultiplyCountˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountˣCommand(*this, h);
    }

    void MultiplyCountˣCommand::init_meta()
    {
        auto w = writer<MultiplyCountˣCommand>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCountˣCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
