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
        m_axis.xx   = Ax::X;
        m_axis.xy   = Ax::Y;
        m_axis.xz   = Ax::Y;
        m_axis.xw   = Ax::Y;
        
        m_axis.yy   = Ax::X;
        m_axis.yz   = Ax::X;
        m_axis.yw   = Ax::X;
    }
    
    BoxLayoutʸ::~BoxLayoutʸ()
    {
    }
}
