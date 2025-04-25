////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʸ)

namespace yq::tachyon {
    SetMaxSizeʸ::SetMaxSizeʸ(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʸ::SetMaxSizeʸ(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMaxSizeʸ::SetMaxSizeʸ(const SetMaxSizeʸ& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMaxSizeʸ::~SetMaxSizeʸ()
    {
    }

    PostCPtr    SetMaxSizeʸ::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʸ(*this, h);
    }
    
    void SetMaxSizeʸ::init_info()
    {
        auto w = writer<SetMaxSizeʸ>();
        w.description("SetMax Size Command in Y");
        w.property("y", &SetMaxSizeʸ::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
