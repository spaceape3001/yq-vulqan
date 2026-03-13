////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScale3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale³DCommand)

namespace yq::tachyon {
    MultiplyScale³DCommand::MultiplyScale³DCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale³DCommand::MultiplyScale³DCommand(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale³DCommand::MultiplyScale³DCommand(const MultiplyScale³DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale³DCommand::~MultiplyScale³DCommand()
    {
    }

    PostCPtr    MultiplyScale³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale³DCommand(*this, h);
    }
    
    void MultiplyScale³DCommand::init_meta()
    {
        auto w = writer<MultiplyScale³DCommand>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale³DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale³DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyScale³DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyScale³DCommand::m_δ).tag(kTag_Save);
    }
}
