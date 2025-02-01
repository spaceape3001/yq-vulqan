////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddMaxSizeX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeˣ)

namespace yq::tachyon {
    AddMaxSizeˣ::AddMaxSizeˣ(const Header&h, double x) : 
        SpatialCommand(h), m_Δx(x)
    {
    }

    AddMaxSizeˣ::AddMaxSizeˣ(const AddMaxSizeˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMaxSizeˣ::~AddMaxSizeˣ()
    {
    }
    
    PostCPtr    AddMaxSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeˣ(*this, h);
    }

    void AddMaxSizeˣ::init_info()
    {
        auto w = writer<AddMaxSizeˣ>();
        w.description("AddMax Size Command in X");
        w.property("Δx", &AddMaxSizeˣ::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
