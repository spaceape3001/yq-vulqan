////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/UIRequest.hpp>
#include <tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIRequest)

namespace yq::tachyon {
    UIRequest::UIRequest(const Header& h) : Request(h)
    {
    }
    
    UIRequest::UIRequest(const UIRequest&cp, const Header&h) : Request(cp, h)
    {
    }

    UIRequest::~UIRequest()
    {
    }
    
    void UIRequest::init_info()
    {
        auto w = writer<UIRequest>();
        w.abstract();
        w.description("UI Request");
    }
}
