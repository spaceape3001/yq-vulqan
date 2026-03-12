////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʸDCommand)

namespace yq::tachyon {
    MultiplyMaxSizeʸDCommand::MultiplyMaxSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSizeʸDCommand::MultiplyMaxSizeʸDCommand(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplyMaxSizeʸDCommand::MultiplyMaxSizeʸDCommand(const MultiplyMaxSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMaxSizeʸDCommand::~MultiplyMaxSizeʸDCommand()
    {
    }

    PostCPtr    MultiplyMaxSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʸDCommand(*this, h);
    }
    
    void MultiplyMaxSizeʸDCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeʸDCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δy", &MultiplyMaxSizeʸDCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
