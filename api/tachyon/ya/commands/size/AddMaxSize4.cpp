////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddMaxSize4.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize⁴)

namespace yq::tachyon {
    AddMaxSize⁴::AddMaxSize⁴(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize⁴::AddMaxSize⁴(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize⁴::AddMaxSize⁴(const AddMaxSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize⁴::~AddMaxSize⁴()
    {
    }

    PostCPtr    AddMaxSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize⁴(*this, h);
    }
    
    void AddMaxSize⁴::init_info()
    {
        auto w = writer<AddMaxSize⁴>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize⁴::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize⁴::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize⁴::Δz).tag(kTag_Log);
        w.property("Δw", &AddMaxSize⁴::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize⁴::m_Δ).tag(kTag_Save);
    }
}
