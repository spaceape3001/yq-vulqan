////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddSizeX.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeˣ)

namespace yq::tachyon {
    AddSizeˣ::AddSizeˣ(const Header&h, double x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddSizeˣ::AddSizeˣ(const AddSizeˣ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddSizeˣ::~AddSizeˣ()
    {
    }
    
    PostCPtr    AddSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeˣ(*this, h);
    }

    void AddSizeˣ::init_info()
    {
        auto w = writer<AddSizeˣ>();
        w.description("Add Size Command in X");
        w.property("Δx", &AddSizeˣ::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
