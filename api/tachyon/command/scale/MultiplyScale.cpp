////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScale.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale)

namespace yq::tachyon {
    MultiplyScale::MultiplyScale(const Header&h, double f) : 
        ScaleCommand(h), m_δ(f)
    {
    }

    MultiplyScale::MultiplyScale(const MultiplyScale& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale::MultiplyScale(const Header&h) : ScaleCommand(h)
    {
    }

    MultiplyScale::~MultiplyScale()
    {
    }
    
    PostCPtr    MultiplyScale::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale(*this, h);
    }

    void MultiplyScale::init_info()
    {
        auto w = writer<MultiplyScale>();
        w.description("Multiply Scale Command");
        w.property("δ", &MultiplyScale::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
