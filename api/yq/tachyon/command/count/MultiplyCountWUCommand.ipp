////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountWUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountʷUCommand)

namespace yq::tachyon {
    MultiplyCountʷUCommand::MultiplyCountʷUCommand(const Header&h) : 
        CountCommand(h)
    {
    }

    MultiplyCountʷUCommand::MultiplyCountʷUCommand(const Header&h, unsigned x) : 
        CountCommand(h), m_δw(x)
    {
    }

    MultiplyCountʷUCommand::MultiplyCountʷUCommand(const MultiplyCountʷUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyCountʷUCommand::~MultiplyCountʷUCommand()
    {
    }
    
    PostCPtr    MultiplyCountʷUCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountʷUCommand(*this, h);
    }

    void MultiplyCountʷUCommand::init_meta()
    {
        auto w = writer<MultiplyCountʷUCommand>();
        w.description("Multiply Count Command");
        w.property("δw", &MultiplyCountʷUCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
