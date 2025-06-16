////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleˣCommand)

namespace yq::tachyon {
    MultiplyScaleˣCommand::MultiplyScaleˣCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScaleˣCommand::MultiplyScaleˣCommand(const Header&h, double x) : 
        ScaleCommand(h), m_δx(x)
    {
    }

    MultiplyScaleˣCommand::MultiplyScaleˣCommand(const MultiplyScaleˣCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyScaleˣCommand::~MultiplyScaleˣCommand()
    {
    }
    
    PostCPtr    MultiplyScaleˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleˣCommand(*this, h);
    }

    void MultiplyScaleˣCommand::init_info()
    {
        auto w = writer<MultiplyScaleˣCommand>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScaleˣCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
