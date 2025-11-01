////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScale2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale²Command)

namespace yq::tachyon {
    MultiplyScale²Command::MultiplyScale²Command(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale²Command::MultiplyScale²Command(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale²Command::MultiplyScale²Command(const MultiplyScale²Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale²Command::~MultiplyScale²Command()
    {
    }

    PostCPtr    MultiplyScale²Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale²Command(*this, h);
    }
    
    void MultiplyScale²Command::init_meta()
    {
        auto w = writer<MultiplyScale²Command>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale²Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale²Command::δy).tag(kTag_Log);
        w.property("δ", &MultiplyScale²Command::m_δ).tag(kTag_Save);
    }
}
