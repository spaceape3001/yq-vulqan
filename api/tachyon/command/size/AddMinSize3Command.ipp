////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSize3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize³Command)

namespace yq::tachyon {
    AddMinSize³Command::AddMinSize³Command(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize³Command::AddMinSize³Command(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize³Command::AddMinSize³Command(const AddMinSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize³Command::~AddMinSize³Command()
    {
    }

    PostCPtr    AddMinSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize³Command(*this, h);
    }
    
    void AddMinSize³Command::init_meta()
    {
        auto w = writer<AddMinSize³Command>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize³Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize³Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize³Command::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMinSize³Command::m_Δ).tag(kTag_Save);
    }
}
