////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize)

namespace yq::tachyon {
    MultiplySize::MultiplySize(const Header&h, double f) : 
        SizeCommand(h), m_δ(f)
    {
    }

    MultiplySize::MultiplySize(const MultiplySize& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize::MultiplySize(const Header&h) : SizeCommand(h)
    {
    }

    MultiplySize::~MultiplySize()
    {
    }
    
    PostCPtr    MultiplySize::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize(*this, h);
    }

    void MultiplySize::init_info()
    {
        auto w = writer<MultiplySize>();
        w.description("Multiply Size Command");
        w.property("δ", &MultiplySize::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
