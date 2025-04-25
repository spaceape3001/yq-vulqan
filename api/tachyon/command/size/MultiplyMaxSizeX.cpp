////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeˣ)

namespace yq::tachyon {
    MultiplyMaxSizeˣ::MultiplyMaxSizeˣ(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSizeˣ::MultiplyMaxSizeˣ(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplyMaxSizeˣ::MultiplyMaxSizeˣ(const MultiplyMaxSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMaxSizeˣ::~MultiplyMaxSizeˣ()
    {
    }
    
    PostCPtr    MultiplyMaxSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeˣ(*this, h);
    }

    void MultiplyMaxSizeˣ::init_info()
    {
        auto w = writer<MultiplyMaxSizeˣ>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSizeˣ::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
