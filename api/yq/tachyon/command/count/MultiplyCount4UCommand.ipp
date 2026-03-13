////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount⁴Command)

namespace yq::tachyon {
    MultiplyCount⁴Command::MultiplyCount⁴Command(const Header& h) : 
        CountCommand(h)
    {
    }

    MultiplyCount⁴Command::MultiplyCount⁴Command(const Header& h, const Vector4U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount⁴Command::MultiplyCount⁴Command(const MultiplyCount⁴Command& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCount⁴Command::~MultiplyCount⁴Command()
    {
    }

    PostCPtr    MultiplyCount⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount⁴Command(*this, h);
    }
    
    void MultiplyCount⁴Command::init_meta()
    {
        auto w = writer<MultiplyCount⁴Command>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount⁴Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyCount⁴Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyCount⁴Command::δz).tag(kTag_Log);
        w.property("δw", &MultiplyCount⁴Command::δw).tag(kTag_Log);
        w.property("δ", &MultiplyCount⁴Command::m_δ).tag(kTag_Save);
    }
}
