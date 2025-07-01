////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPosition2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition²Command)

namespace yq::tachyon {
    MultiplyPosition²Command::MultiplyPosition²Command(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition²Command::MultiplyPosition²Command(const Header& h, const Vector2D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition²Command::MultiplyPosition²Command(const MultiplyPosition²Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition²Command::~MultiplyPosition²Command()
    {
    }

    PostCPtr    MultiplyPosition²Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition²Command(*this, h);
    }
    
    void MultiplyPosition²Command::init_info()
    {
        auto w = writer<MultiplyPosition²Command>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition²Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition²Command::δy).tag(kTag_Log);
        w.property("δ", &MultiplyPosition²Command::m_δ).tag(kTag_Save);
    }
}
