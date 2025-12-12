////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition¹Command)

namespace yq::tachyon {
    AddPosition¹Command::AddPosition¹Command(const Header& h) : 
        PositionCommand(h)
    {
    }

    AddPosition¹Command::AddPosition¹Command(const Header& h, const Vector1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition¹Command::AddPosition¹Command(const AddPosition¹Command&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition¹Command::~AddPosition¹Command()
    {
    }
    
    PostCPtr    AddPosition¹Command::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition¹Command(*this, h);
    }

    void AddPosition¹Command::init_meta()
    {
        auto w = writer<AddPosition¹Command>();
        w.description("Position AddPosition Command in 1D");
        w.property("Δx", &AddPosition¹Command::Δx).tag(kTag_Log);
        w.property("Δ", &AddPosition¹Command::m_Δ).tag(kTag_Save);
    }
}
