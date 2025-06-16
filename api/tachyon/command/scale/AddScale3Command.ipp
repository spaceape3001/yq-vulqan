////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScale3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale³Command)

namespace yq::tachyon {
    AddScale³Command::AddScale³Command(const Header& h) : ScaleCommand(h)
    {
    }
    
    AddScale³Command::AddScale³Command(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale³Command::AddScale³Command(const AddScale³Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale³Command::~AddScale³Command()
    {
    }

    PostCPtr    AddScale³Command::clone(rebind_k, const Header&h) const 
    {
        return new AddScale³Command(*this, h);
    }
    
    void AddScale³Command::init_info()
    {
        auto w = writer<AddScale³Command>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale³Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale³Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddScale³Command::Δz).tag(kTag_Log);
        w.property("Δ",  &AddScale³Command::m_Δ).tag(kTag_Save);
    }
}
