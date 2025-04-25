////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScaleX.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleˣ)

namespace yq::tachyon {
    AddScaleˣ::AddScaleˣ(const Header&h, double x) : 
        ScaleCommand(h), m_Δx(x)
    {
    }

    AddScaleˣ::AddScaleˣ(const AddScaleˣ& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddScaleˣ::~AddScaleˣ()
    {
    }
    
    PostCPtr    AddScaleˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleˣ(*this, h);
    }

    void AddScaleˣ::init_info()
    {
        auto w = writer<AddScaleˣ>();
        w.description("Add Scale Command in X");
        w.property("Δx", &AddScaleˣ::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
