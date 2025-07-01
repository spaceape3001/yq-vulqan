////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPosition1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition¹Command)

namespace yq::tachyon {
    MultiplyPosition¹Command::MultiplyPosition¹Command(const Header& h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPosition¹Command::MultiplyPosition¹Command(const Header& h, const Vector1D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition¹Command::MultiplyPosition¹Command(const MultiplyPosition¹Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyPosition¹Command::~MultiplyPosition¹Command()
    {
    }
    
    PostCPtr    MultiplyPosition¹Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition¹Command(*this, h);
    }

    void MultiplyPosition¹Command::init_info()
    {
        auto w = writer<MultiplyPosition¹Command>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition¹Command::δx).tag(kTag_Log);
        w.property("δ", &MultiplyPosition¹Command::m_δ).tag(kTag_Save);
    }
}
