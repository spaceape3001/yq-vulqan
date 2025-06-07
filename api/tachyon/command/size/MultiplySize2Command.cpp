////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySize2Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize²Command)

namespace yq::tachyon {
    MultiplySize²Command::MultiplySize²Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize²Command::MultiplySize²Command(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize²Command::MultiplySize²Command(const MultiplySize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize²Command::~MultiplySize²Command()
    {
    }

    PostCPtr    MultiplySize²Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize²Command(*this, h);
    }
    
    void MultiplySize²Command::init_info()
    {
        auto w = writer<MultiplySize²Command>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize²Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize²Command::δy).tag(kTag_Log);
        w.property("δ", &MultiplySize²Command::m_δ).tag(kTag_Save);
    }
}
