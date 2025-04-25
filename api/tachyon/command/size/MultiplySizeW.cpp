////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySizeW.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeʷ)

namespace yq::tachyon {
    MultiplySizeʷ::MultiplySizeʷ(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplySizeʷ::MultiplySizeʷ(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplySizeʷ::MultiplySizeʷ(const MultiplySizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplySizeʷ::~MultiplySizeʷ()
    {
    }
    
    PostCPtr    MultiplySizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeʷ(*this, h);
    }

    void MultiplySizeʷ::init_info()
    {
        auto w = writer<MultiplySizeʷ>();
        w.description("Multiply Size Command");
        w.property("δw", &MultiplySizeʷ::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
