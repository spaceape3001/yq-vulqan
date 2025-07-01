////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSize3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize³Command)

namespace yq::tachyon {
    AddSize³Command::AddSize³Command(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize³Command::AddSize³Command(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize³Command::AddSize³Command(const AddSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize³Command::~AddSize³Command()
    {
    }

    PostCPtr    AddSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new AddSize³Command(*this, h);
    }
    
    void AddSize³Command::init_info()
    {
        auto w = writer<AddSize³Command>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize³Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize³Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize³Command::Δz).tag(kTag_Log);
        w.property("Δ",  &AddSize³Command::m_Δ).tag(kTag_Save);
    }
}
