////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleCommand)

namespace yq::tachyon {
    MultiplyScaleCommand::MultiplyScaleCommand(const Header&h, double f) : 
        ScaleCommand(h), m_δ(f)
    {
    }

    MultiplyScaleCommand::MultiplyScaleCommand(const MultiplyScaleCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScaleCommand::MultiplyScaleCommand(const Header&h) : ScaleCommand(h)
    {
    }

    MultiplyScaleCommand::~MultiplyScaleCommand()
    {
    }
    
    PostCPtr    MultiplyScaleCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleCommand(*this, h);
    }

    void MultiplyScaleCommand::init_info()
    {
        auto w = writer<MultiplyScaleCommand>();
        w.description("Multiply Scale Command");
        w.property("δ", &MultiplyScaleCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
