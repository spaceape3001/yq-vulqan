////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class ThreadOverclockEditUI : public UIElement {
        YQ_OBJECT_DECLARE(ThreadOverclockEditUI, UIElement)
    public:
        ThreadOverclockEditUI(StdThread, UIFlags flags={});
        ThreadOverclockEditUI(const ThreadOverclockEditUI&);
        ~ThreadOverclockEditUI();
        
        ThreadOverclockEditUI* clone() const override;
        static void init_meta();
    
        void render() override;
        
        //  Refine this to a double... with getter/setter?
    
    private:
        StdThread   m_stdThread;
        ThreadID    m_thread;
        TypedID     m_sendTo;
    };
}
