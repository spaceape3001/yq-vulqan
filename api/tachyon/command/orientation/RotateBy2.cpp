////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/RotateBy2.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Spinor2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy²)

namespace yq::tachyon {
    RotateBy²::RotateBy²(const Header& h, const Spinor2D&δ) : 
        OrientationCommand(h), m_δ(δ)
    {
    }
    
    RotateBy²::RotateBy²(const Header& h, Radian δ) :
        OrientationCommand(h), m_δ(CCW, δ)
    {
    }
    
    RotateBy²::RotateBy²(const RotateBy²& cp, const Header& h) : 
        OrientationCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    RotateBy²::~RotateBy²()
    {
    }
    
    PostCPtr    RotateBy²::clone(rebind_k, const Header& h) const 
    {
        return new RotateBy²(*this, h);
    }

    void RotateBy²::init_info()
    {
        auto w = writer<RotateBy²>();
        w.description("Position RotateBy Command in 3D");
        w.property("δa", &RotateBy²::δa);
        w.property("δxy", &RotateBy²::δxy);
    }
}
