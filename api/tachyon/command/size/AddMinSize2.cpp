////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSize2.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize²)

namespace yq::tachyon {
    AddMinSize²::AddMinSize²(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMinSize²::AddMinSize²(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize²::AddMinSize²(const AddMinSize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize²::~AddMinSize²()
    {
    }

    PostCPtr    AddMinSize²::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize²(*this, h);
    }
    
    void AddMinSize²::init_info()
    {
        auto w = writer<AddMinSize²>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize²::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize²::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMinSize²::m_Δ).tag(kTag_Save);
    }
}
