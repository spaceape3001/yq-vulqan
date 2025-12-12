////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount¹Command)

namespace yq::tachyon {
    MultiplyCount¹Command::MultiplyCount¹Command(const Header& h) : 
        CountCommand(h)
    {
    }
    
    MultiplyCount¹Command::MultiplyCount¹Command(const Header& h, const Vector1D& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount¹Command::MultiplyCount¹Command(const MultiplyCount¹Command& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyCount¹Command::~MultiplyCount¹Command()
    {
    }
    
    PostCPtr    MultiplyCount¹Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount¹Command(*this, h);
    }

    void MultiplyCount¹Command::init_meta()
    {
        auto w = writer<MultiplyCount¹Command>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount¹Command::δx).tag(kTag_Log);
        w.property("δ", &MultiplyCount¹Command::m_δ).tag(kTag_Save);
    }
}
