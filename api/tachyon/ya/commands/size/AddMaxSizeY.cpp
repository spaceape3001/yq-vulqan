////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddMaxSizeY.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʸ)

namespace yq::tachyon {
    AddMaxSizeʸ::AddMaxSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMaxSizeʸ::AddMaxSizeʸ(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMaxSizeʸ::AddMaxSizeʸ(const AddMaxSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMaxSizeʸ::~AddMaxSizeʸ()
    {
    }

    PostCPtr    AddMaxSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʸ(*this, h);
    }
    
    void AddMaxSizeʸ::init_info()
    {
        auto w = writer<AddMaxSizeʸ>();
        w.description("AddMax Size Command in Y");
        w.property("Δy", &AddMaxSizeʸ::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
