////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplySizeY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeʸ)

namespace yq::tachyon {
    MultiplySizeʸ::MultiplySizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySizeʸ::MultiplySizeʸ(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplySizeʸ::MultiplySizeʸ(const MultiplySizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplySizeʸ::~MultiplySizeʸ()
    {
    }

    PostCPtr    MultiplySizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeʸ(*this, h);
    }
    
    void MultiplySizeʸ::init_info()
    {
        auto w = writer<MultiplySizeʸ>();
        w.description("Multiply Size Command");
        w.property("δy", &MultiplySizeʸ::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
