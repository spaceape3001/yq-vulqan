////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSize2.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize²)

namespace yq::tachyon {
    AddSize²::AddSize²(const Header&h) : SizeCommand(h)
    {
    }
    
    AddSize²::AddSize²(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize²::AddSize²(const AddSize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize²::~AddSize²()
    {
    }

    PostCPtr    AddSize²::clone(rebind_k, const Header&h) const 
    {
        return new AddSize²(*this, h);
    }
    
    void AddSize²::init_info()
    {
        auto w = writer<AddSize²>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize²::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize²::Δy).tag(kTag_Log);
        w.property("Δ",  &AddSize²::m_Δ).tag(kTag_Save);
    }
}
