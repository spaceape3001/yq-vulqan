////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize)

namespace yq::tachyon {
    MultiplyMaxSize::MultiplyMaxSize(const Header&h, double f) : 
        SizeCommand(h), m_δ(f)
    {
    }

    MultiplyMaxSize::MultiplyMaxSize(const MultiplyMaxSize& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize::MultiplyMaxSize(const Header&h) : SizeCommand(h)
    {
    }

    MultiplyMaxSize::~MultiplyMaxSize()
    {
    }
    
    PostCPtr    MultiplyMaxSize::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize(*this, h);
    }

    void MultiplyMaxSize::init_meta()
    {
        auto w = writer<MultiplyMaxSize>();
        w.description("MultiplyMax Size Command");
        w.property("δ", &MultiplyMaxSize::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
