////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSize4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize⁴)

namespace yq::tachyon {
    AddMinSize⁴::AddMinSize⁴(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize⁴::AddMinSize⁴(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize⁴::AddMinSize⁴(const AddMinSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize⁴::~AddMinSize⁴()
    {
    }

    PostCPtr    AddMinSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize⁴(*this, h);
    }
    
    void AddMinSize⁴::init_info()
    {
        auto w = writer<AddMinSize⁴>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize⁴::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize⁴::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize⁴::Δz).tag(kTag_Log);
        w.property("Δw", &AddMinSize⁴::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMinSize⁴::m_Δ).tag(kTag_Save);
    }
}
