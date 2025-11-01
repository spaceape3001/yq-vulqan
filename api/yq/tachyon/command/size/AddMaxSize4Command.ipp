////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/AddMaxSize4Command.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize⁴Command)

namespace yq::tachyon {
    AddMaxSize⁴Command::AddMaxSize⁴Command(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize⁴Command::AddMaxSize⁴Command(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize⁴Command::AddMaxSize⁴Command(const AddMaxSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize⁴Command::~AddMaxSize⁴Command()
    {
    }

    PostCPtr    AddMaxSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize⁴Command(*this, h);
    }
    
    void AddMaxSize⁴Command::init_meta()
    {
        auto w = writer<AddMaxSize⁴Command>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize⁴Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize⁴Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize⁴Command::Δz).tag(kTag_Log);
        w.property("Δw", &AddMaxSize⁴Command::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize⁴Command::m_Δ).tag(kTag_Save);
    }
}
