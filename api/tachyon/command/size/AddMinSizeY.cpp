////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSizeY.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʸ)

namespace yq::tachyon {
    AddMinSizeʸ::AddMinSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMinSizeʸ::AddMinSizeʸ(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMinSizeʸ::AddMinSizeʸ(const AddMinSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMinSizeʸ::~AddMinSizeʸ()
    {
    }

    PostCPtr    AddMinSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʸ(*this, h);
    }
    
    void AddMinSizeʸ::init_info()
    {
        auto w = writer<AddMinSizeʸ>();
        w.description("AddMin Size Command in Y");
        w.property("Δy", &AddMinSizeʸ::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
