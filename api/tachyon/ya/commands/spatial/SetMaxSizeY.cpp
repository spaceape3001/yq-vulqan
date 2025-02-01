////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMaxSizeY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʸ)

namespace yq::tachyon {
    SetMaxSizeʸ::SetMaxSizeʸ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMaxSizeʸ::SetMaxSizeʸ(const Header& h, double v) : 
        SpatialCommand(h), m_y(v)
    {
    }

    SetMaxSizeʸ::SetMaxSizeʸ(const SetMaxSizeʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMaxSizeʸ::~SetMaxSizeʸ()
    {
    }

    PostCPtr    SetMaxSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʸ(*this, h);
    }
    
    void SetMaxSizeʸ::init_info()
    {
        auto w = writer<SetMaxSizeʸ>();
        w.description("SetMax Size Command in Y");
        w.property("y", &SetMaxSizeʸ::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
