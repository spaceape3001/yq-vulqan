////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddMaxSizeY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʸ)

namespace yq::tachyon {
    AddMaxSizeʸ::AddMaxSizeʸ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    AddMaxSizeʸ::AddMaxSizeʸ(const Header& h, double y) : 
        SpatialCommand(h), m_Δy(y)
    {
    }
    
    AddMaxSizeʸ::AddMaxSizeʸ(const AddMaxSizeʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMaxSizeʸ::~AddMaxSizeʸ()
    {
    }

    PostCPtr    AddMaxSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʸ(*this, h);
    }
    
    void AddMaxSizeʸ::init_info()
    {
        auto w = writer<AddMaxSizeʸ>();
        w.description("AddMax Size Command in Y");
        w.property("Δy", &AddMaxSizeʸ::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
