////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSize2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize²Command)

namespace yq::tachyon {
    MultiplyMaxSize²Command::MultiplyMaxSize²Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize²Command::MultiplyMaxSize²Command(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize²Command::MultiplyMaxSize²Command(const MultiplyMaxSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize²Command::~MultiplyMaxSize²Command()
    {
    }

    PostCPtr    MultiplyMaxSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize²Command(*this, h);
    }
    
    void MultiplyMaxSize²Command::init_meta()
    {
        auto w = writer<MultiplyMaxSize²Command>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize²Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize²Command::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize²Command::m_δ).tag(kTag_Save);
    }
}
