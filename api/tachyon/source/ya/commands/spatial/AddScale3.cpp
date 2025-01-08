////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScale3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale³)

namespace yq::tachyon {
    AddScale³::AddScale³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_scale(v)
    {
    }

    AddScale³::AddScale³(const AddScale³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    AddScale³::~AddScale³()
    {
    }

    PostCPtr    AddScale³::clone(rebind_k, const Header&h) const 
    {
        return new AddScale³(*this, h);
    }
    
    void AddScale³::init_info()
    {
        auto w = writer<AddScale³>();
        w.description("Add Scale Command");
        w.property("x", &AddScale³::x);
        w.property("y", &AddScale³::y);
        w.property("z", &AddScale³::z);
    }
}
