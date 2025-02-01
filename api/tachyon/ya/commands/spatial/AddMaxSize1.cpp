////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddMaxSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize¹)

namespace yq::tachyon {
    AddMaxSize¹::AddMaxSize¹(const Header& h) : SpatialCommand(h)
    {
    }

    AddMaxSize¹::AddMaxSize¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_Δ(v)
    {
    }
    
    AddMaxSize¹::AddMaxSize¹(const AddMaxSize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMaxSize¹::~AddMaxSize¹()
    {
    }
    
    PostCPtr    AddMaxSize¹::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize¹(*this, h);
    }

    void AddMaxSize¹::init_info()
    {
        auto w = writer<AddMaxSize¹>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize¹::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize¹::m_Δ).tag(kTag_Save);
    }
}
