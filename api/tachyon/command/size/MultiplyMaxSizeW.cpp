////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSizeW.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʷ)

namespace yq::tachyon {
    MultiplyMaxSizeʷ::MultiplyMaxSizeʷ(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSizeʷ::MultiplyMaxSizeʷ(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplyMaxSizeʷ::MultiplyMaxSizeʷ(const MultiplyMaxSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyMaxSizeʷ::~MultiplyMaxSizeʷ()
    {
    }
    
    PostCPtr    MultiplyMaxSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʷ(*this, h);
    }

    void MultiplyMaxSizeʷ::init_info()
    {
        auto w = writer<MultiplyMaxSizeʷ>();
        w.description("MultiplyMax Size Command");
        w.property("δw", &MultiplyMaxSizeʷ::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
