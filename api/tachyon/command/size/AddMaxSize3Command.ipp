////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSize3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize³Command)

namespace yq::tachyon {
    AddMaxSize³Command::AddMaxSize³Command(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize³Command::AddMaxSize³Command(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize³Command::AddMaxSize³Command(const AddMaxSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize³Command::~AddMaxSize³Command()
    {
    }

    PostCPtr    AddMaxSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize³Command(*this, h);
    }
    
    void AddMaxSize³Command::init_info()
    {
        auto w = writer<AddMaxSize³Command>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize³Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize³Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize³Command::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize³Command::m_Δ).tag(kTag_Save);
    }
}
