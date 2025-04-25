////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSize1.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize¹)

namespace yq::tachyon {
    AddMinSize¹::AddMinSize¹(const Header& h) : SizeCommand(h)
    {
    }

    AddMinSize¹::AddMinSize¹(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMinSize¹::AddMinSize¹(const AddMinSize¹& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMinSize¹::~AddMinSize¹()
    {
    }
    
    PostCPtr    AddMinSize¹::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize¹(*this, h);
    }

    void AddMinSize¹::init_info()
    {
        auto w = writer<AddMinSize¹>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize¹::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMinSize¹::m_Δ).tag(kTag_Save);
    }
}
