////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Reply.hpp>

namespace yq::tachyon {
    class Viewer;
    class ViewerRequest;

    class ViewerReply : public Reply {
        YQ_OBJECT_DECLARE(ViewerReply, Reply)
    public:

        static void init_info();

    protected:
    
        ViewerReply(const Header&, const RequestCPtr&);
        ViewerReply(const ViewerReply&, const Header&);
        virtual ~ViewerReply();
        
    private:
        ViewerReply(const ViewerReply&) = delete;
        ViewerReply(ViewerReply&&) = delete;
        ViewerReply& operator=(const ViewerReply&) = delete;
        ViewerReply& operator=(ViewerReply&&) = delete;
    };
}
