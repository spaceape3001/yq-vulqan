////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount3UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount³UCommand)

namespace yq::tachyon {
    AddCount³UCommand::AddCount³UCommand(const Header& h) : CountCommand(h)
    {
    }
    
    AddCount³UCommand::AddCount³UCommand(const Header& h, const Vector3U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }

    AddCount³UCommand::AddCount³UCommand(const AddCount³UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddCount³UCommand::~AddCount³UCommand()
    {
    }

    PostCPtr    AddCount³UCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCount³UCommand(*this, h);
    }
    
    void AddCount³UCommand::init_meta()
    {
        auto w = writer<AddCount³UCommand>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount³UCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddCount³UCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddCount³UCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddCount³UCommand::m_Δ).tag(kTag_Save);
    }
}
