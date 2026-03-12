////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeʸDCommand)

namespace yq::tachyon {
    MultiplyMinSizeʸDCommand::MultiplyMinSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSizeʸDCommand::MultiplyMinSizeʸDCommand(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplyMinSizeʸDCommand::MultiplyMinSizeʸDCommand(const MultiplyMinSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMinSizeʸDCommand::~MultiplyMinSizeʸDCommand()
    {
    }

    PostCPtr    MultiplyMinSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeʸDCommand(*this, h);
    }
    
    void MultiplyMinSizeʸDCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeʸDCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δy", &MultiplyMinSizeʸDCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
