////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount1UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount¹UCommand)

namespace yq::tachyon {
    AddCount¹UCommand::AddCount¹UCommand(const Header& h) : CountCommand(h)
    {
    }

    AddCount¹UCommand::AddCount¹UCommand(const Header& h, const Vector1U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }
    
    AddCount¹UCommand::AddCount¹UCommand(const AddCount¹UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddCount¹UCommand::~AddCount¹UCommand()
    {
    }
    
    PostCPtr    AddCount¹UCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCount¹UCommand(*this, h);
    }

    void AddCount¹UCommand::init_meta()
    {
        auto w = writer<AddCount¹UCommand>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount¹UCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddCount¹UCommand::m_Δ).tag(kTag_Save);
    }
}
