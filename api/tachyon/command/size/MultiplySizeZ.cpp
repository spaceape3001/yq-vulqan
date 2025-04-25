////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplySizeZ.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeᶻ)

namespace yq::tachyon {
    MultiplySizeᶻ::MultiplySizeᶻ(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySizeᶻ::MultiplySizeᶻ(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplySizeᶻ::MultiplySizeᶻ(const MultiplySizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplySizeᶻ::~MultiplySizeᶻ()
    {
    }

    PostCPtr    MultiplySizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeᶻ(*this, h);
    }
    
    void MultiplySizeᶻ::init_info()
    {
        auto w = writer<MultiplySizeᶻ>();
        w.description("Multiply Size Command");
        w.property("δz", &MultiplySizeᶻ::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
