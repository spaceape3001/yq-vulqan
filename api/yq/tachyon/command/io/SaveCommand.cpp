////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/io/SaveCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveCommand)

namespace yq::tachyon {

    SaveCommand::SaveCommand(const Header&h, const std::filesystem::path& fp) : SaveCommand(h, fp, Param())
    {
    }

    SaveCommand::SaveCommand(const Header&h, const std::filesystem::path& fp, const Param& p) : 
        IOCommand(h), m_filepath(fp), m_tachyons(p.tachyons), m_thread(p.thread), m_options(p.options)
    {
    }

    SaveCommand::SaveCommand(const SaveCommand& cp, const Header& h) : IOCommand(cp, h), 
        m_filepath(cp.m_filepath), m_tachyons(cp.m_tachyons), m_thread(cp.m_thread), m_options(cp.m_options)
    {
    }
    
    SaveCommand::~SaveCommand()
    {
    }

    PostCPtr    SaveCommand::clone(rebind_k, const Header&h) const 
    {
        return new SaveCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SaveCommand::init_meta()
    {
        auto w = writer<SaveCommand>();
        w.description("Save Command");
    }
}
