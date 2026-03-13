////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScale4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale⁴DCommand)

namespace yq::tachyon {
    MultiplyScale⁴DCommand::MultiplyScale⁴DCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale⁴DCommand::MultiplyScale⁴DCommand(const Header& h, const Vector4D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale⁴DCommand::MultiplyScale⁴DCommand(const MultiplyScale⁴DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale⁴DCommand::~MultiplyScale⁴DCommand()
    {
    }

    PostCPtr    MultiplyScale⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale⁴DCommand(*this, h);
    }
    
    void MultiplyScale⁴DCommand::init_meta()
    {
        auto w = writer<MultiplyScale⁴DCommand>();
        w.description("Multiply Scale Command");
        w.property("δw", &MultiplyScale⁴DCommand::δw).tag(kTag_Log);
        w.property("δx", &MultiplyScale⁴DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale⁴DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyScale⁴DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyScale⁴DCommand::m_δ).tag(kTag_Save);
    }
}
