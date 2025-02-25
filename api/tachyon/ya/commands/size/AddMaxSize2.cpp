////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddMaxSize2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize²)

namespace yq::tachyon {
    AddMaxSize²::AddMaxSize²(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMaxSize²::AddMaxSize²(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize²::AddMaxSize²(const AddMaxSize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize²::~AddMaxSize²()
    {
    }

    PostCPtr    AddMaxSize²::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize²(*this, h);
    }
    
    void AddMaxSize²::init_info()
    {
        auto w = writer<AddMaxSize²>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize²::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize²::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize²::m_Δ).tag(kTag_Save);
    }
}
