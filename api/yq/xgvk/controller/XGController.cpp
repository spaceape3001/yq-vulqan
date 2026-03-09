////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGController.hpp"
#include <yq/graph/GDocument.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/ControllerMetaWriter.hpp>
#include <yq/xg/XGRuntime.hpp>
#include <yq/xgvk/api/XGContextVk.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::XGController)

namespace yq::tachyon {
    XGController::XGController()
    {
    }
    
    XGController::~XGController()
    {
    }

    bool    XGController::_add(GDocumentCPtr doc)
    {
        if(!doc){
            tachyonError << "XGController::add(" << doc->url() << "): unable to install null graph.";
            return false;
        }
        if(std::error_code ec = m_runtime -> add(GGraph(READ_ONLY, doc)); ec != std::error_code()){
            tachyonError << "XGController::add(" << doc->url() << "): unable to install due to: " << ec.message();
            return false;
        }
        return true;
    }

    bool   XGController::_execute(const Context& ctx)
    {
        XGRuntimeOptions    options;

        auto x  = m_runtime->execute(*m_context, options);
        return _okay("execute", x);
    }
    
    bool   XGController:: _okay(const char*z, const xg_result_t&x)
    {
        if(std::get_if<std::monostate>(&x))
            return true;
            
        if(auto p = std::get_if<std::error_code>(&x)){
            tachyonError << "XGController::" << z << "(): graph error: " << p->message();
            m_error = true;
            return false;
        }
        
        if(std::get_if<bool>(&x))
            return true;
        if(std::get_if<done_k>(&x)){
            m_done  = true;
            return true;
        }
        if(std::get_if<error_k>(&x)){
            tachyonError << "XGController::" << z << "(): unspecified graph error";
            return false;
        }
        if(std::get_if<limit_k>(&x)){
            tachyonWarning << "XGController::" << z << "(): iteration limit exceeded";
            return true;
        }

        if(std::get_if<wait_k>(&x))
            return true;
        if(std::get_if<xg_cursor_t>(&x))
            return true;
        
        tachyonWarning << "XGController::" << z << "(): Unhandled execution result";
        return false;
    }

    bool   XGController::_step(const Context& ctx)
    {
        XGRuntimeOptions    options;

        auto x  = m_runtime->execute(*m_context, options);
        return _okay("step", x);
    }

    bool    XGController::graphs() const
    {
        return m_tick || m_setup || m_tear; // or others
    }

    Execution   XGController::setup(const Context& ctx) 
    {
        Execution   x   = Controller::setup(ctx);
        if(!std::get_if<std::monostate>(&x))
            return x;

        if(!m_context)
            m_context   = std::make_unique<XGContextVk>();
        
        if(!m_runtime){
            m_runtime   = std::make_unique<XGRuntime>();
            
            if(m_setup && !_add(m_setup))
                return ABORT;
            if(m_tick && !_add(m_tick))
                return ABORT;
            if(m_tear && !_add(m_tear))
                return ABORT;
                
            for(auto& g : m_reflex){
                if(!_add(g))
                    return ABORT;
            }
                
            //  install reflexes....
        }

        if(!m_tickReq){
            if(m_setup){
                if(!_execute(ctx))
                    return ABORT;
                if(!m_context->tick_request && !m_done)
                    return WAIT;
            }

            m_tickReq = true;
            if(m_tick)
                m_runtime -> primary(SET, m_tick->id());
            
            std::vector<gid_t>  all;
            if(m_tick){
                // more... TODO... sort this out.... (need more granular control to the runtime TODO)
            }
        }
        
        return {};
    }

    
    Execution   XGController::teardown(const Context& ctx) 
    {
        if(!m_tearStart){
            if(m_tear)
                m_runtime -> primary(SET, m_tear->id());
            m_tearStart = true;
        }
        
        if(!m_tearDone && m_tear){
            if(_execute(ctx) && !m_done && !m_context->tear_finished)
                return WAIT;
        }
        m_tearDone  = true;
        if(m_runtime)
            m_runtime   = {};
        if(m_context)
            m_context   = {};
        return Controller::teardown(ctx);
    }

    Execution   XGController::tick(const Context& ctx) 
    {
        if(!m_pause){
            if(!_execute(ctx))
                m_pause = true;
        } else if(m_step){
            _step(ctx);
            m_step = false;
        }
        
        if(m_context->tear_request)
            return TEARDOWN;
        
        return Controller::tick(ctx);
    }

        
    void XGController::init_meta()
    {
        auto w = writer<XGController>();
        w.description("Executive Graph Controller");
        w.resource("setup", &XGController::m_setup);
        w.resource("tear", &XGController::m_tear);
        w.resource("tick", &XGController::m_tick);
        w.resources("reflex", &XGController::m_reflex);
        
        //  reflexes...
    }
}
