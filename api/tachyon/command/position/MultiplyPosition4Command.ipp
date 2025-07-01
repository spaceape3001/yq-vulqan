////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPosition4Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition⁴Command)

namespace yq::tachyon {
    MultiplyPosition⁴Command::MultiplyPosition⁴Command(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition⁴Command::MultiplyPosition⁴Command(const Header& h, const Vector4D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition⁴Command::MultiplyPosition⁴Command(const MultiplyPosition⁴Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition⁴Command::~MultiplyPosition⁴Command()
    {
    }

    PostCPtr    MultiplyPosition⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition⁴Command(*this, h);
    }
    
    void MultiplyPosition⁴Command::init_info()
    {
        auto w = writer<MultiplyPosition⁴Command>();
        w.description("Multiply Position Command");
        w.property("δw", &MultiplyPosition⁴Command::δw).tag(kTag_Log);
        w.property("δx", &MultiplyPosition⁴Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition⁴Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyPosition⁴Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplyPosition⁴Command::m_δ).tag(kTag_Save);
    }
}
