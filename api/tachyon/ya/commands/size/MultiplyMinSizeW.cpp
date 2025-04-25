////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMinSizeW.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeʷ)

namespace yq::tachyon {
    MultiplyMinSizeʷ::MultiplyMinSizeʷ(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSizeʷ::MultiplyMinSizeʷ(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplyMinSizeʷ::MultiplyMinSizeʷ(const MultiplyMinSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyMinSizeʷ::~MultiplyMinSizeʷ()
    {
    }
    
    PostCPtr    MultiplyMinSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeʷ(*this, h);
    }

    void MultiplyMinSizeʷ::init_info()
    {
        auto w = writer<MultiplyMinSizeʷ>();
        w.description("MultiplyMin Size Command");
        w.property("δw", &MultiplyMinSizeʷ::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
