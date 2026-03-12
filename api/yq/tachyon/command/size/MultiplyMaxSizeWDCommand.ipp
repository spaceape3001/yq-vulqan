////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeʷDCommand)

namespace yq::tachyon {
    MultiplyMaxSizeʷDCommand::MultiplyMaxSizeʷDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSizeʷDCommand::MultiplyMaxSizeʷDCommand(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplyMaxSizeʷDCommand::MultiplyMaxSizeʷDCommand(const MultiplyMaxSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyMaxSizeʷDCommand::~MultiplyMaxSizeʷDCommand()
    {
    }
    
    PostCPtr    MultiplyMaxSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeʷDCommand(*this, h);
    }

    void MultiplyMaxSizeʷDCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeʷDCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δw", &MultiplyMaxSizeʷDCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
