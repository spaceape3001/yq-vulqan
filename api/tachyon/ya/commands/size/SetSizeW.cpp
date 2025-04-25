////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetSizeW.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʷ)

namespace yq::tachyon {
    SetSizeʷ::SetSizeʷ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʷ::SetSizeʷ(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetSizeʷ::SetSizeʷ(const SetSizeʷ& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetSizeʷ::~SetSizeʷ()
    {
    }

    PostCPtr    SetSizeʷ::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʷ(*this, h);
    }
    
    void SetSizeʷ::init_info()
    {
        auto w = writer<SetSizeʷ>();
        w.description("Set Size Command in X");
        w.property("w", &SetSizeʷ::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
