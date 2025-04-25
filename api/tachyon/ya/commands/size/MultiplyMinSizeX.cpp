////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeˣ)

namespace yq::tachyon {
    MultiplyMinSizeˣ::MultiplyMinSizeˣ(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSizeˣ::MultiplyMinSizeˣ(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplyMinSizeˣ::MultiplyMinSizeˣ(const MultiplyMinSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMinSizeˣ::~MultiplyMinSizeˣ()
    {
    }
    
    PostCPtr    MultiplyMinSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeˣ(*this, h);
    }

    void MultiplyMinSizeˣ::init_info()
    {
        auto w = writer<MultiplyMinSizeˣ>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSizeˣ::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
