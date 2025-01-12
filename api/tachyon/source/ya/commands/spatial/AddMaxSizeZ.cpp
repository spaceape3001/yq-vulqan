////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddMaxSizeZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeᶻ)

namespace yq::tachyon {
    AddMaxSizeᶻ::AddMaxSizeᶻ(const Header&h) : 
        SpatialCommand(h)
    {
    }
    
    AddMaxSizeᶻ::AddMaxSizeᶻ(const Header&h, double z) : 
        SpatialCommand(h), m_Δz(z)
    {
    }

    AddMaxSizeᶻ::AddMaxSizeᶻ(const AddMaxSizeᶻ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMaxSizeᶻ::~AddMaxSizeᶻ()
    {
    }

    PostCPtr    AddMaxSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeᶻ(*this, h);
    }
    
    void AddMaxSizeᶻ::init_info()
    {
        auto w = writer<AddMaxSizeᶻ>();
        w.description("AddMax Size Command in Z");
        w.property("Δz", &AddMaxSizeᶻ::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
