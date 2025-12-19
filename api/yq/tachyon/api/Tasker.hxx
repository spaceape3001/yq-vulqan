////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Future.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/api/Tasker.hpp>
#include <yq/tachyon/typedef/frame.hpp>

namespace yq::tachyon {
    struct Tasker::Task {
        FrameCPtr               m_frame;
        std::source_location    m_location;
        
        Task();
        virtual ~Task();
        virtual void    cancel() = 0;
        virtual void    execute() = 0;
        virtual void    cancelled() = 0;
    };

    template <typename Pred>
    struct Tasker::SimpleTask : public Task {
        using result_t  = std::invoke_result_t<Pred>;
        using future_t  = Future<result_t>;
        using promise_t = Promise<result_t>;
        
        Pred                m_pred;
        Promise<result_t>   m_promise;
        
        SimpleTask(Pred&& pred) : m_pred(std::move(pred)) 
        {
        }

        void    cancel() override
        {
            m_promise.cancel();
        }
        
        void    cancelled() override
        {
            m_promise.set(CANCEL);
        }
        
        void    execute() override
        {
            if(m_promise.cancelled()){
                m_promise.set(CANCEL);
                return;
            }

            #ifdef NDEBUG
            try {
            #endif
                if constexpr (!std::is_same_v<result_t, void>){
                    m_promise.set( m_pred() );
                } else {
                    m_pred();
                    m_promise.set(DONE);
                }
            
            #ifdef NDEBUG
            }
            catch(std::exception& ex)
            {
                m_promise.set(std::current_exception());
            }
            catch(std::error_code ec)
            {
                m_promise.set(ec);
            }
            catch(...)
            {
                m_promise.set(std::make_exception_ptr(std::exception("Unexpected exception was thrown")));
            }
            #endif
        }
    };

    template <typename Pred>
    auto    Tasker::simple_task(Pred&& pred, const std::source_location& sl)
    {
        if constexpr (std::is_invocable_v<Pred>){
            auto task   = std::make_shared<SimpleTask<Pred>>(std::move(pred));
            schedule(task, sl);
            return task->m_promise.get_future();
        } 
        

        return Future<void>();
    }

    template <typename T, typename Pred> 
    struct Tasker::PromiseTask : public Task {
        
    };

}
