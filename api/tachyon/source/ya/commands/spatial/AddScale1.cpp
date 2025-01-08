////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScale1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale¹)

namespace yq::tachyon {
    AddScale¹::AddScale¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_scale(v)
    {
    }
    
    AddScale¹::AddScale¹(const AddScale¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }

    AddScale¹::~AddScale¹()
    {
    }
    
    PostCPtr    AddScale¹::clone(rebind_k, const Header&h) const 
    {
        return new AddScale¹(*this, h);
    }

    void AddScale¹::init_info()
    {
        auto w = writer<AddScale¹>();
        w.description("Add Scale Command");
        w.property("x", &AddScale¹::x);
    }
}
