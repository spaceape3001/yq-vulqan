////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSize2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize²Command)

namespace yq::tachyon {
    MultiplyMinSize²Command::MultiplyMinSize²Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize²Command::MultiplyMinSize²Command(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize²Command::MultiplyMinSize²Command(const MultiplyMinSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize²Command::~MultiplyMinSize²Command()
    {
    }

    PostCPtr    MultiplyMinSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize²Command(*this, h);
    }
    
    void MultiplyMinSize²Command::init_meta()
    {
        auto w = writer<MultiplyMinSize²Command>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize²Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize²Command::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize²Command::m_δ).tag(kTag_Save);
    }
}
