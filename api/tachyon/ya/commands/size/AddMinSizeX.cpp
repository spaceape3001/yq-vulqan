////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddMinSizeX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeˣ)

namespace yq::tachyon {
    AddMinSizeˣ::AddMinSizeˣ(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMinSizeˣ::AddMinSizeˣ(const AddMinSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMinSizeˣ::~AddMinSizeˣ()
    {
    }
    
    PostCPtr    AddMinSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeˣ(*this, h);
    }

    void AddMinSizeˣ::init_info()
    {
        auto w = writer<AddMinSizeˣ>();
        w.description("AddMin Size Command in X");
        w.property("Δx", &AddMinSizeˣ::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
