////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCountYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCountʸCommand)

namespace yq::tachyon {
    MultiplyCountʸCommand::MultiplyCountʸCommand(const Header& h) : 
        CountCommand(h)
    {
    }
    
    MultiplyCountʸCommand::MultiplyCountʸCommand(const Header& h, unsigned y) : 
        CountCommand(h), m_δy(y)
    {
    }

    MultiplyCountʸCommand::MultiplyCountʸCommand(const MultiplyCountʸCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyCountʸCommand::~MultiplyCountʸCommand()
    {
    }

    PostCPtr    MultiplyCountʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCountʸCommand(*this, h);
    }
    
    void MultiplyCountʸCommand::init_meta()
    {
        auto w = writer<MultiplyCountʸCommand>();
        w.description("Multiply Count Command");
        w.property("δy", &MultiplyCountʸCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
