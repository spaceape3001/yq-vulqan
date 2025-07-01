////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTSXRequest.hpp"
#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveTSXRequest)

namespace yq::tachyon {
    void SaveTSXRequest::init_meta()
    {
        auto w = writer<SaveTSXRequest>();
        w.description("Save tachyons to TSX file");
    }
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, ThreadSpec th, SaveOptions opts) : 
        IORequest(h), m_filepath(fp), m_thread(th), m_options(opts)
    {
    }
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, ThreadSpec th, const TachyonIDSet&tacs, SaveOptions opts) :
        IORequest(h), m_filepath(fp), m_thread(th), m_tachyons(tacs), m_options(opts)
    {
    }
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, ThreadSpec th, TachyonIDSet&&tacs, SaveOptions opts) :
        IORequest(h), m_filepath(fp), m_thread(th), m_tachyons(std::move(tacs)), m_options(opts)
    {
    }
    
    SaveTSXRequest::SaveTSXRequest(const SaveTSXRequest&cp, const Header&h) : IORequest(cp, h), 
        m_filepath(cp.m_filepath), m_thread(cp.m_thread), m_tachyons(cp.m_tachyons), m_options(cp.m_options)
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
