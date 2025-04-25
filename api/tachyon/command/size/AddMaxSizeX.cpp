////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeˣ)

namespace yq::tachyon {
    AddMaxSizeˣ::AddMaxSizeˣ(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMaxSizeˣ::AddMaxSizeˣ(const AddMaxSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMaxSizeˣ::~AddMaxSizeˣ()
    {
    }
    
    PostCPtr    AddMaxSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeˣ(*this, h);
    }

    void AddMaxSizeˣ::init_info()
    {
        auto w = writer<AddMaxSizeˣ>();
        w.description("AddMax Size Command in X");
        w.property("Δx", &AddMaxSizeˣ::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
