////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetSizeY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʸ)

namespace yq::tachyon {
    SetSizeʸ::SetSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʸ::SetSizeʸ(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetSizeʸ::SetSizeʸ(const SetSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetSizeʸ::~SetSizeʸ()
    {
    }

    PostCPtr    SetSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʸ(*this, h);
    }
    
    void SetSizeʸ::init_info()
    {
        auto w = writer<SetSizeʸ>();
        w.description("Set Size Command in Y");
        w.property("y", &SetSizeʸ::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
