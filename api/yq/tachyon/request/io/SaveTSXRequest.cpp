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
    
    SaveTSXRequest::SaveTSXRequest(const Header&h, const std::filesystem::path& fp, const Config& cfg) : 
        IORequest(h), m_filepath(fp), m_config(cfg)
    {
    }
    
    
    SaveTSXRequest::SaveTSXRequest(const SaveTSXRequest&cp, const Header&h) : IORequest(cp, h), 
        m_filepath(cp.m_filepath), m_config(cp.m_config)
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
