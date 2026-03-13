////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScaleXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleˣDCommand)

namespace yq::tachyon {
    MultiplyScaleˣDCommand::MultiplyScaleˣDCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScaleˣDCommand::MultiplyScaleˣDCommand(const Header&h, double x) : 
        ScaleCommand(h), m_δx(x)
    {
    }

    MultiplyScaleˣDCommand::MultiplyScaleˣDCommand(const MultiplyScaleˣDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyScaleˣDCommand::~MultiplyScaleˣDCommand()
    {
    }
    
    PostCPtr    MultiplyScaleˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleˣDCommand(*this, h);
    }

    void MultiplyScaleˣDCommand::init_meta()
    {
        auto w = writer<MultiplyScaleˣDCommand>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScaleˣDCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
