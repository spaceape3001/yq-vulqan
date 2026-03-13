////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount¹Command)

namespace yq::tachyon {
    AddCount¹Command::AddCount¹Command(const Header& h) : CountCommand(h)
    {
    }

    AddCount¹Command::AddCount¹Command(const Header& h, const Vector1U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }
    
    AddCount¹Command::AddCount¹Command(const AddCount¹Command& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddCount¹Command::~AddCount¹Command()
    {
    }
    
    PostCPtr    AddCount¹Command::clone(rebind_k, const Header&h) const 
    {
        return new AddCount¹Command(*this, h);
    }

    void AddCount¹Command::init_meta()
    {
        auto w = writer<AddCount¹Command>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount¹Command::Δx).tag(kTag_Log);
        w.property("Δ",  &AddCount¹Command::m_Δ).tag(kTag_Save);
    }
}
