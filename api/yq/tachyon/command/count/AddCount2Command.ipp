////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount²Command)

namespace yq::tachyon {
    AddCount²Command::AddCount²Command(const Header&h) : CountCommand(h)
    {
    }
    
    AddCount²Command::AddCount²Command(const Header& h, const Vector2U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }

    AddCount²Command::AddCount²Command(const AddCount²Command& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddCount²Command::~AddCount²Command()
    {
    }

    PostCPtr    AddCount²Command::clone(rebind_k, const Header&h) const 
    {
        return new AddCount²Command(*this, h);
    }
    
    void AddCount²Command::init_meta()
    {
        auto w = writer<AddCount²Command>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount²Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddCount²Command::Δy).tag(kTag_Log);
        w.property("Δ",  &AddCount²Command::m_Δ).tag(kTag_Save);
    }
}
