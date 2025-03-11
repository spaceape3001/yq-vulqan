////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BoxLayoutY.hpp"
#include <yt/ui/LayoutInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BoxLayoutʸ)

namespace yq::tachyon {
    void BoxLayoutʸ::init_info()
    {
        auto w = writer<BoxLayoutʸ>();
        w.description("Box layout in the Y-direction");
    }
    
    BoxLayoutʸ::BoxLayoutʸ()
    {
        m_dims.axis.xx   = Ax::X;
        m_dims.axis.xy   = Ax::Y;
        m_dims.axis.xz   = Ax::Y;
        m_dims.axis.xw   = Ax::Y;
        
        m_dims.axis.yy   = Ax::X;
        m_dims.axis.yz   = Ax::X;
        m_dims.axis.yw   = Ax::X;
    }
    
    BoxLayoutʸ::~BoxLayoutʸ()
    {
    }
}
