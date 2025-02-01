////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMaxSizeY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʸ)

namespace yq::tachyon {
    MultiplyMaxSizeʸ::MultiplyMaxSizeʸ(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyMaxSizeʸ::MultiplyMaxSizeʸ(const Header& h, double y) : 
        SpatialCommand(h), m_δy(y)
    {
    }

    MultiplyMaxSizeʸ::MultiplyMaxSizeʸ(const MultiplyMaxSizeʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMaxSizeʸ::~MultiplyMaxSizeʸ()
    {
    }

    PostCPtr    MultiplyMaxSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʸ(*this, h);
    }
    
    void MultiplyMaxSizeʸ::init_info()
    {
        auto w = writer<MultiplyMaxSizeʸ>();
        w.description("MultiplyMax Size Command");
        w.property("δy", &MultiplyMaxSizeʸ::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
