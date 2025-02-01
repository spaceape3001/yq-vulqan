////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize¹)

namespace yq::tachyon {
    AddSize¹::AddSize¹(const Header& h) : SpatialCommand(h)
    {
    }

    AddSize¹::AddSize¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_Δ(v)
    {
    }
    
    AddSize¹::AddSize¹(const AddSize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddSize¹::~AddSize¹()
    {
    }
    
    PostCPtr    AddSize¹::clone(rebind_k, const Header&h) const 
    {
        return new AddSize¹(*this, h);
    }

    void AddSize¹::init_info()
    {
        auto w = writer<AddSize¹>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize¹::Δx).tag(kTag_Log);
        w.property("Δ",  &AddSize¹::m_Δ).tag(kTag_Save);
    }
}
