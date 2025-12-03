////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTSXRequest.hpp"
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveTSXRequest)

namespace yq::tachyon {
    void SaveTSXRequest::init_meta()
    {
        auto w = writer<SaveTSXRequest>();
        w.description("Save tachyons to TSX file");
    }
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, ThreadSpec th, SaveFlags opts) : 
        IORequest(h), m_filepath(fp), m_thread(th), m_flags(opts)
    {
    }
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, ThreadSpec th, const TachyonIDSet&tacs, SaveFlags opts) :
        IORequest(h), m_filepath(fp), m_thread(th), m_tachyons(tacs), m_flags(opts)
    {
    }
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, ThreadSpec th, TachyonIDSet&&tacs, SaveFlags opts) :
        IORequest(h), m_filepath(fp), m_thread(th), m_tachyons(std::move(tacs)), m_flags(opts)
    {
    }
    
    SaveTSXRequest::SaveTSXRequest(const SaveTSXRequest&cp, const Header&h) : IORequest(cp, h), 
        m_filepath(cp.m_filepath), m_thread(cp.m_thread), m_tachyons(cp.m_tachyons), m_flags(cp.m_flags)
    {
    }

    SaveTSXRequest::~SaveTSXRequest()
    {
    }
    
    PostCPtr SaveTSXRequest::clone(rebind_k, const Header&h) const
    {
        return new SaveTSXRequest(*this, h);
    }
}
