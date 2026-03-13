////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScaleYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleʸDCommand)

namespace yq::tachyon {
    MultiplyScaleʸDCommand::MultiplyScaleʸDCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScaleʸDCommand::MultiplyScaleʸDCommand(const Header& h, double y) : 
        ScaleCommand(h), m_δy(y)
    {
    }

    MultiplyScaleʸDCommand::MultiplyScaleʸDCommand(const MultiplyScaleʸDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyScaleʸDCommand::~MultiplyScaleʸDCommand()
    {
    }

    PostCPtr    MultiplyScaleʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleʸDCommand(*this, h);
    }
    
    void MultiplyScaleʸDCommand::init_meta()
    {
        auto w = writer<MultiplyScaleʸDCommand>();
        w.description("Multiply Scale Command");
        w.property("δy", &MultiplyScaleʸDCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
