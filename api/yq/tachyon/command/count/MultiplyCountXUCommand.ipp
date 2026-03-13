////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountXUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountˣUCommand)

namespace yq::tachyon {
    MultiplyCountˣUCommand::MultiplyCountˣUCommand(const Header&h) : 
        CountCommand(h)
    {
    }

    MultiplyCountˣUCommand::MultiplyCountˣUCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_δx(x)
    {
    }

    MultiplyCountˣUCommand::MultiplyCountˣUCommand(const MultiplyCountˣUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyCountˣUCommand::~MultiplyCountˣUCommand()
    {
    }
    
    PostCPtr    MultiplyCountˣUCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountˣUCommand(*this, h);
    }

    void MultiplyCountˣUCommand::init_meta()
    {
        auto w = writer<MultiplyCountˣUCommand>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCountˣUCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
