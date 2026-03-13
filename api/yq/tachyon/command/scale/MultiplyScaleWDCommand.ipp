////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScaleWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleʷDCommand)

namespace yq::tachyon {
    MultiplyScaleʷDCommand::MultiplyScaleʷDCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScaleʷDCommand::MultiplyScaleʷDCommand(const Header&h, double z) : 
        ScaleCommand(h), m_δw(z)
    {
    }
    
    MultiplyScaleʷDCommand::MultiplyScaleʷDCommand(const MultiplyScaleʷDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δw(cp.m_δw)
    {
    }

    MultiplyScaleʷDCommand::~MultiplyScaleʷDCommand()
    {
    }

    PostCPtr    MultiplyScaleʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleʷDCommand(*this, h);
    }
    
    void MultiplyScaleʷDCommand::init_meta()
    {
        auto w = writer<MultiplyScaleʷDCommand>();
        w.description("Multiply Scale Command");
        w.property("δw", &MultiplyScaleʷDCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
