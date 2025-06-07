////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScale3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale³Command)

namespace yq::tachyon {
    MultiplyScale³Command::MultiplyScale³Command(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale³Command::MultiplyScale³Command(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale³Command::MultiplyScale³Command(const MultiplyScale³Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale³Command::~MultiplyScale³Command()
    {
    }

    PostCPtr    MultiplyScale³Command::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale³Command(*this, h);
    }
    
    void MultiplyScale³Command::init_info()
    {
        auto w = writer<MultiplyScale³Command>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale³Command::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale³Command::δy).tag(kTag_Log);
        w.property("δz", &MultiplyScale³Command::δz).tag(kTag_Log);
        w.property("δ", &MultiplyScale³Command::m_δ).tag(kTag_Save);
    }
}
