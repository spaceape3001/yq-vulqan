////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize)

namespace yq::tachyon {
    MultiplyMinSize::MultiplyMinSize(const Header&h, double f) : 
        SizeCommand(h), m_δ(f)
    {
    }

    MultiplyMinSize::MultiplyMinSize(const MultiplyMinSize& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize::MultiplyMinSize(const Header&h) : SizeCommand(h)
    {
    }

    MultiplyMinSize::~MultiplyMinSize()
    {
    }
    
    PostCPtr    MultiplyMinSize::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize(*this, h);
    }

    void MultiplyMinSize::init_info()
    {
        auto w = writer<MultiplyMinSize>();
        w.description("MultiplyMin Size Command");
        w.property("δ", &MultiplyMinSize::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
