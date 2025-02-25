////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMaxSizeZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeᶻ)

namespace yq::tachyon {
    MultiplyMaxSizeᶻ::MultiplyMaxSizeᶻ(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSizeᶻ::MultiplyMaxSizeᶻ(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplyMaxSizeᶻ::MultiplyMaxSizeᶻ(const MultiplyMaxSizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyMaxSizeᶻ::~MultiplyMaxSizeᶻ()
    {
    }

    PostCPtr    MultiplyMaxSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeᶻ(*this, h);
    }
    
    void MultiplyMaxSizeᶻ::init_info()
    {
        auto w = writer<MultiplyMaxSizeᶻ>();
        w.description("MultiplyMax Size Command");
        w.property("δz", &MultiplyMaxSizeᶻ::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
