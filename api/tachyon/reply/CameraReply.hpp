////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Reply.hpp>

namespace yq::tachyon {
    class CameraReply : public Reply {
        YQ_OBJECT_DECLARE(CameraReply, Reply)
    public:

        static void init_info();
    
    protected:
    
        CameraReply(const Header&, const RequestCPtr&);
        CameraReply(const CameraReply&, const Header&);
        virtual ~CameraReply();
        
    private:
        CameraReply(const CameraReply&) = delete;
        CameraReply(CameraReply&&) = delete;
        CameraReply& operator=(const CameraReply&) = delete;
        CameraReply& operator=(CameraReply&&) = delete;
    };
}
