////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount⁴Command)

namespace yq::tachyon {
    AddCount⁴Command::AddCount⁴Command(const Header& h) : CountCommand(h)
    {
    }
    
    AddCount⁴Command::AddCount⁴Command(const Header& h, const Vector4U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }

    AddCount⁴Command::AddCount⁴Command(const AddCount⁴Command& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddCount⁴Command::~AddCount⁴Command()
    {
    }

    PostCPtr    AddCount⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new AddCount⁴Command(*this, h);
    }
    
    void AddCount⁴Command::init_meta()
    {
        auto w = writer<AddCount⁴Command>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount⁴Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddCount⁴Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddCount⁴Command::Δz).tag(kTag_Log);
        w.property("Δw", &AddCount⁴Command::Δw).tag(kTag_Log);
        w.property("Δ",  &AddCount⁴Command::m_Δ).tag(kTag_Save);
    }
}
