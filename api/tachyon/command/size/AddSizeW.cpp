////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSizeW.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʷ)

namespace yq::tachyon {
    AddSizeʷ::AddSizeʷ(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddSizeʷ::AddSizeʷ(const AddSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddSizeʷ::~AddSizeʷ()
    {
    }
    
    PostCPtr    AddSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʷ(*this, h);
    }

    void AddSizeʷ::init_info()
    {
        auto w = writer<AddSizeʷ>();
        w.description("Add Size Command in X");
        w.property("Δw", &AddSizeʷ::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
