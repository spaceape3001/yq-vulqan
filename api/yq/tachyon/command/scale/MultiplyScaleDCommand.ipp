////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScaleDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleDCommand)

namespace yq::tachyon {
    MultiplyScaleDCommand::MultiplyScaleDCommand(const Header&h, double f) : 
        ScaleCommand(h), m_δ(f)
    {
    }

    MultiplyScaleDCommand::MultiplyScaleDCommand(const MultiplyScaleDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScaleDCommand::MultiplyScaleDCommand(const Header&h) : ScaleCommand(h)
    {
    }

    MultiplyScaleDCommand::~MultiplyScaleDCommand()
    {
    }
    
    PostCPtr    MultiplyScaleDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleDCommand(*this, h);
    }

    void MultiplyScaleDCommand::init_meta()
    {
        auto w = writer<MultiplyScaleDCommand>();
        w.description("Multiply Scale Command");
        w.property("δ", &MultiplyScaleDCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
