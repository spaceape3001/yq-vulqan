////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount²Command)

namespace yq::tachyon {
    MultiplyCount²Command::MultiplyCount²Command(const Header& h) : 
        CountCommand(h)
    {
    }

    MultiplyCount²Command::MultiplyCount²Command(const Header& h, const Vector2U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount²Command::MultiplyCount²Command(const MultiplyCount²Command& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCount²Command::~MultiplyCount²Command()
    {
    }

    PostCPtr    MultiplyCount²Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount²Command(*this, h);
    }
    
    void MultiplyCount²Command::init_meta()
    {
        auto w = writer<MultiplyCount²Command>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount²Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyCount²Command::δy).tag(kTag_Log);
        w.property("δ", &MultiplyCount²Command::m_δ).tag(kTag_Save);
    }
}
