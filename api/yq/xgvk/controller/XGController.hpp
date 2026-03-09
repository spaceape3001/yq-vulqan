////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Controller.hpp>
#include <yq/typedef/xg_runtime.hpp>
#include <yq/typedef/g_document.hpp>
#include <yq/xg/types.hpp>
#include <yq/xgvk/typedef/xg_context_vk.hpp>

namespace yq::tachyon {
    struct XGContextVk;
    class XGController : public Controller {
        YQ_TACHYON_DECLARE(XGController, Controller)
    public:
    
        XGController();
        ~XGController();
        
        bool    graphs() const;
        
        static void init_meta();
        
    protected:
        virtual Execution   setup(const Context&) override;
        virtual Execution   tick(const Context&) override;
        virtual Execution   teardown(const Context&) override;
        
    private:
        
        std::vector<GDocumentCPtr>  m_reflex;
        GDocumentCPtr               m_setup;
        GDocumentCPtr               m_tear;
        GDocumentCPtr               m_tick;
        
        //  and reflexes.... (will be a vector...)

        XGRuntimeUPtr       m_runtime;
        XGContextVkUPtr     m_context;
        
        bool                m_pause     = false;
        bool                m_done      = false;
        bool                m_error     = false;
        bool                m_tickReq   = false;
        bool                m_tearStart = false;
        bool                m_tearDone  = false;
        bool                m_step      = false;
        
        bool    _add(GDocumentCPtr);
        bool    _okay(const char*, const xg_result_t&);
        bool    _execute(const Context&);
        bool    _step(const Context&);
        
        //  And... some debugging/stepping capability... resetting, etc
    };
}
