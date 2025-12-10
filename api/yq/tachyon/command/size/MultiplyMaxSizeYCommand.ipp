////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSizeYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʸCommand)

namespace yq::tachyon {
    MultiplyMaxSizeʸCommand::MultiplyMaxSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSizeʸCommand::MultiplyMaxSizeʸCommand(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplyMaxSizeʸCommand::MultiplyMaxSizeʸCommand(const MultiplyMaxSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMaxSizeʸCommand::~MultiplyMaxSizeʸCommand()
    {
    }

    PostCPtr    MultiplyMaxSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʸCommand(*this, h);
    }
    
    void MultiplyMaxSizeʸCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeʸCommand>();
        w.description("MultiplyMax Size Command");
        w.property("δy", &MultiplyMaxSizeʸCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
