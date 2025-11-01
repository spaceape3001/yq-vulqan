////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {
    class Editor;
    class EditorRequest;

    class EditorReply : public Reply {
        YQ_OBJECT_DECLARE(EditorReply, Reply)
    public:

        static void init_meta();

    protected:
    
        EditorReply(const Header&, const RequestCPtr&);
        EditorReply(const EditorReply&, const Header&);
        virtual ~EditorReply();
        
    private:
        EditorReply(const EditorReply&) = delete;
        EditorReply(EditorReply&&) = delete;
        EditorReply& operator=(const EditorReply&) = delete;
        EditorReply& operator=(EditorReply&&) = delete;
    };
}
