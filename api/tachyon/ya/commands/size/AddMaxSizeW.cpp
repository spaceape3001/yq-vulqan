////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddMaxSizeW.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʷ)

namespace yq::tachyon {
    AddMaxSizeʷ::AddMaxSizeʷ(const Header&h, double x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMaxSizeʷ::AddMaxSizeʷ(const AddMaxSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMaxSizeʷ::~AddMaxSizeʷ()
    {
    }
    
    PostCPtr    AddMaxSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʷ(*this, h);
    }

    void AddMaxSizeʷ::init_info()
    {
        auto w = writer<AddMaxSizeʷ>();
        w.description("AddMax Size Command in X");
        w.property("Δw", &AddMaxSizeʷ::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
