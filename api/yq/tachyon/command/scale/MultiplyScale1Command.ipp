////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScale1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale¹Command)

namespace yq::tachyon {
    MultiplyScale¹Command::MultiplyScale¹Command(const Header& h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScale¹Command::MultiplyScale¹Command(const Header& h, const Vector1D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale¹Command::MultiplyScale¹Command(const MultiplyScale¹Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyScale¹Command::~MultiplyScale¹Command()
    {
    }
    
    PostCPtr    MultiplyScale¹Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale¹Command(*this, h);
    }

    void MultiplyScale¹Command::init_meta()
    {
        auto w = writer<MultiplyScale¹Command>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale¹Command::δx).tag(kTag_Log);
        w.property("δ", &MultiplyScale¹Command::m_δ).tag(kTag_Save);
    }
}
