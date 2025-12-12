////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount³Command)

namespace yq::tachyon {
    AddCount³Command::AddCount³Command(const Header& h) : CountCommand(h)
    {
    }
    
    AddCount³Command::AddCount³Command(const Header& h, const Vector3U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }

    AddCount³Command::AddCount³Command(const AddCount³Command& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddCount³Command::~AddCount³Command()
    {
    }

    PostCPtr    AddCount³Command::clone(rebind_k, const Header&h) const 
    {
        return new AddCount³Command(*this, h);
    }
    
    void AddCount³Command::init_meta()
    {
        auto w = writer<AddCount³Command>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount³Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddCount³Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddCount³Command::Δz).tag(kTag_Log);
        w.property("Δ",  &AddCount³Command::m_Δ).tag(kTag_Save);
    }
}
