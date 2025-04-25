////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSize4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize⁴)

namespace yq::tachyon {
    AddSize⁴::AddSize⁴(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize⁴::AddSize⁴(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize⁴::AddSize⁴(const AddSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize⁴::~AddSize⁴()
    {
    }

    PostCPtr    AddSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new AddSize⁴(*this, h);
    }
    
    void AddSize⁴::init_info()
    {
        auto w = writer<AddSize⁴>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize⁴::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize⁴::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize⁴::Δz).tag(kTag_Log);
        w.property("Δw", &AddSize⁴::Δw).tag(kTag_Log);
        w.property("Δ",  &AddSize⁴::m_Δ).tag(kTag_Save);
    }
}
