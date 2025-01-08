////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScale2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale²)

namespace yq::tachyon {
    AddScale²::AddScale²(const Header& h, const Vector2D& v) : 
        SpatialCommand(h), m_scale(v)
    {
    }

    AddScale²::AddScale²(const AddScale²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    AddScale²::~AddScale²()
    {
    }

    PostCPtr    AddScale²::clone(rebind_k, const Header&h) const 
    {
        return new AddScale²(*this, h);
    }
    
    void AddScale²::init_info()
    {
        auto w = writer<AddScale²>();
        w.description("Add Scale Command");
        w.property("x", &AddScale²::x);
        w.property("y", &AddScale²::y);
    }
}
