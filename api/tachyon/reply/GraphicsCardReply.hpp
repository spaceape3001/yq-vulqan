////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Reply.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class GraphicsCardReply : public Reply {
        YQ_OBJECT_DECLARE(GraphicsCardReply, Reply)
    public:
    
        static void init_meta();

    protected:
        GraphicsCardReply(const Header&, const RequestCPtr&);
        GraphicsCardReply(const GraphicsCardReply&, const Header&);
        virtual ~GraphicsCardReply();
        
    private:
        GraphicsCardReply(const GraphicsCardReply&) = delete;
        GraphicsCardReply(GraphicsCardReply&&) = delete;
        GraphicsCardReply& operator=(const GraphicsCardReply&) = delete;
        GraphicsCardReply& operator=(GraphicsCardReply&&) = delete;
    };
}
