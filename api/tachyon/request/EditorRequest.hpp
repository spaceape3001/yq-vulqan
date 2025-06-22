////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Request.hpp>

namespace yq::tachyon {
    class Editor;

    class EditorRequest : public Request {
        YQ_OBJECT_DECLARE(EditorRequest, Request)
    public:
    
        static void init_info();

    protected:
        EditorRequest(const Header&);
        EditorRequest(const EditorRequest&, const Header&);
        virtual ~EditorRequest();

    private:
        EditorRequest(const EditorRequest&) = delete;
        EditorRequest(EditorRequest&&) = delete;
        EditorRequest& operator=(const EditorRequest&) = delete;
        EditorRequest& operator=(EditorRequest&&) = delete;
    };
}
