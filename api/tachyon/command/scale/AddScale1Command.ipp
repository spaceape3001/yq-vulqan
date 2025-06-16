////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScale1Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale¹Command)

namespace yq::tachyon {
    AddScale¹Command::AddScale¹Command(const Header& h) : ScaleCommand(h)
    {
    }

    AddScale¹Command::AddScale¹Command(const Header& h, const Vector1D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }
    
    AddScale¹Command::AddScale¹Command(const AddScale¹Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddScale¹Command::~AddScale¹Command()
    {
    }
    
    PostCPtr    AddScale¹Command::clone(rebind_k, const Header&h) const 
    {
        return new AddScale¹Command(*this, h);
    }

    void AddScale¹Command::init_info()
    {
        auto w = writer<AddScale¹Command>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale¹Command::Δx).tag(kTag_Log);
        w.property("Δ",  &AddScale¹Command::m_Δ).tag(kTag_Save);
    }
}
