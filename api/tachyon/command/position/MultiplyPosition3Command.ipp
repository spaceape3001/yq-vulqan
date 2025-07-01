////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPosition3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition³Command)

namespace yq::tachyon {
    MultiplyPosition³Command::MultiplyPosition³Command(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition³Command::MultiplyPosition³Command(const Header& h, const Vector3D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition³Command::MultiplyPosition³Command(const MultiplyPosition³Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition³Command::~MultiplyPosition³Command()
    {
    }

    PostCPtr    MultiplyPosition³Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition³Command(*this, h);
    }
    
    void MultiplyPosition³Command::init_meta()
    {
        auto w = writer<MultiplyPosition³Command>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition³Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition³Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyPosition³Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplyPosition³Command::m_δ).tag(kTag_Save);
    }
}
