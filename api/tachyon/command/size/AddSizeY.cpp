////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSizeY.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʸ)

namespace yq::tachyon {
    AddSizeʸ::AddSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddSizeʸ::AddSizeʸ(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddSizeʸ::AddSizeʸ(const AddSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddSizeʸ::~AddSizeʸ()
    {
    }

    PostCPtr    AddSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʸ(*this, h);
    }
    
    void AddSizeʸ::init_info()
    {
        auto w = writer<AddSizeʸ>();
        w.description("Add Size Command in Y");
        w.property("Δy", &AddSizeʸ::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
