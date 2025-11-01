////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleʸCommand)

namespace yq::tachyon {
    MultiplyScaleʸCommand::MultiplyScaleʸCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScaleʸCommand::MultiplyScaleʸCommand(const Header& h, double y) : 
        ScaleCommand(h), m_δy(y)
    {
    }

    MultiplyScaleʸCommand::MultiplyScaleʸCommand(const MultiplyScaleʸCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyScaleʸCommand::~MultiplyScaleʸCommand()
    {
    }

    PostCPtr    MultiplyScaleʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleʸCommand(*this, h);
    }
    
    void MultiplyScaleʸCommand::init_meta()
    {
        auto w = writer<MultiplyScaleʸCommand>();
        w.description("Multiply Scale Command");
        w.property("δy", &MultiplyScaleʸCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
