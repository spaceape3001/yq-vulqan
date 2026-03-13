////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountYUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountʸUCommand)

namespace yq::tachyon {
    MultiplyCountʸUCommand::MultiplyCountʸUCommand(const Header& h) : 
        CountCommand(h)
    {
    }
    
    MultiplyCountʸUCommand::MultiplyCountʸUCommand(const Header& h, unsigned y) : 
        CountCommand(h), m_δy(y)
    {
    }

    MultiplyCountʸUCommand::MultiplyCountʸUCommand(const MultiplyCountʸUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyCountʸUCommand::~MultiplyCountʸUCommand()
    {
    }

    PostCPtr    MultiplyCountʸUCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountʸUCommand(*this, h);
    }
    
    void MultiplyCountʸUCommand::init_meta()
    {
        auto w = writer<MultiplyCountʸUCommand>();
        w.description("Multiply Count Command");
        w.property("δy", &MultiplyCountʸUCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
