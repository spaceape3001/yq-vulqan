////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMaxSizeY.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʸ)

namespace yq::tachyon {
    MultiplyMaxSizeʸ::MultiplyMaxSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSizeʸ::MultiplyMaxSizeʸ(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplyMaxSizeʸ::MultiplyMaxSizeʸ(const MultiplyMaxSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMaxSizeʸ::~MultiplyMaxSizeʸ()
    {
    }

    PostCPtr    MultiplyMaxSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʸ(*this, h);
    }
    
    void MultiplyMaxSizeʸ::init_info()
    {
        auto w = writer<MultiplyMaxSizeʸ>();
        w.description("MultiplyMax Size Command");
        w.property("δy", &MultiplyMaxSizeʸ::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
