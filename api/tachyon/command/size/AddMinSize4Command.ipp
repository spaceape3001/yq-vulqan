////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSize4Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize⁴Command)

namespace yq::tachyon {
    AddMinSize⁴Command::AddMinSize⁴Command(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize⁴Command::AddMinSize⁴Command(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize⁴Command::AddMinSize⁴Command(const AddMinSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize⁴Command::~AddMinSize⁴Command()
    {
    }

    PostCPtr    AddMinSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize⁴Command(*this, h);
    }
    
    void AddMinSize⁴Command::init_info()
    {
        auto w = writer<AddMinSize⁴Command>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize⁴Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize⁴Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize⁴Command::Δz).tag(kTag_Log);
        w.property("Δw", &AddMinSize⁴Command::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMinSize⁴Command::m_Δ).tag(kTag_Save);
    }
}
