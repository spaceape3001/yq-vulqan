////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddMinSizeW.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʷ)

namespace yq::tachyon {
    AddMinSizeʷ::AddMinSizeʷ(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMinSizeʷ::AddMinSizeʷ(const AddMinSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMinSizeʷ::~AddMinSizeʷ()
    {
    }
    
    PostCPtr    AddMinSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʷ(*this, h);
    }

    void AddMinSizeʷ::init_info()
    {
        auto w = writer<AddMinSizeʷ>();
        w.description("AddMin Size Command in X");
        w.property("Δw", &AddMinSizeʷ::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
