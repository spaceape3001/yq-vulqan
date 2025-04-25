////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSizeZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeᶻ)

namespace yq::tachyon {
    MultiplyMinSizeᶻ::MultiplyMinSizeᶻ(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSizeᶻ::MultiplyMinSizeᶻ(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplyMinSizeᶻ::MultiplyMinSizeᶻ(const MultiplyMinSizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyMinSizeᶻ::~MultiplyMinSizeᶻ()
    {
    }

    PostCPtr    MultiplyMinSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeᶻ(*this, h);
    }
    
    void MultiplyMinSizeᶻ::init_info()
    {
        auto w = writer<MultiplyMinSizeᶻ>();
        w.description("MultiplyMin Size Command");
        w.property("δz", &MultiplyMinSizeᶻ::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
