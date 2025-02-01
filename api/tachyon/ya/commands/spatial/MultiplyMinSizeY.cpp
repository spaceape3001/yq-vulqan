////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMinSizeY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeʸ)

namespace yq::tachyon {
    MultiplyMinSizeʸ::MultiplyMinSizeʸ(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyMinSizeʸ::MultiplyMinSizeʸ(const Header& h, double y) : 
        SpatialCommand(h), m_δy(y)
    {
    }

    MultiplyMinSizeʸ::MultiplyMinSizeʸ(const MultiplyMinSizeʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMinSizeʸ::~MultiplyMinSizeʸ()
    {
    }

    PostCPtr    MultiplyMinSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeʸ(*this, h);
    }
    
    void MultiplyMinSizeʸ::init_info()
    {
        auto w = writer<MultiplyMinSizeʸ>();
        w.description("MultiplyMin Size Command");
        w.property("δy", &MultiplyMinSizeʸ::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
