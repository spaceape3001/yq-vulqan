////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "AsyncTask.hpp"
#include <tachyon/api/ID.hpp>
#include <yq/core/Future.hpp>
#include <yq/core/Ref.hpp>
#include <exception>
#include <system_error>

namespace yq::tachyon {

    //! A tasker that's not attached to anything
    template <typename Pred>
    class UnattachedAsyncTasker : public AsyncTask {
    public:
        using result_t  = std::invoke_result_t<Pred>;
        using future_t  = Future<result_t>;
        using promise_t = Promise<result_t>;
        
        UnattachedAsyncTasker(promise_t&& promise, Pred&& pred) : m_promise(promise), m_pred(std::move(pred))
        {
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

        future_t        future() 
        {
            return m_promise.get_future();
        }

    private:

        promise_t       m_promise;
        Pred            m_pred;
    };
    

    //! A tasker that needs to keep a reference valid
    template <typename R, typename Pred>
    class RefAttachedAsyncTasker : public AsyncTask {
    public:
        using result_t  = std::invoke_result_t<Pred>;
        using future_t  = Future<result_t>;
        using promise_t = Promise<result_t>;
        
        RefAttachedAsyncTasker(Ref<R>ref, promise_t&& promise, Pred&& pred) : m_ref(ref), m_promise(promise), m_pred(std::move(pred))
        {
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

        future_t        future() 
        {
            return m_promise.get_future();
        }

    private:

        Ref<R>          m_ref;
        promise_t       m_promise;
        Pred            m_pred;
    };

    template <typename Pred>
    auto async_task(ThreadID th, Pred&&pred)
    {
        auto at     = std::make_unique<UnattachedAsyncTasker<Pred>>(std::move(pred));
        auto ret    = at->future();
        schedule_this(th, std::move(at));
        return ret;
    }

    template <typename Pred>
    auto async_task(StdThread th, Pred&&pred)
    {
        auto at     = std::make_unique<UnattachedAsyncTasker<Pred>>(std::move(pred));
        auto ret    = at->future();
        schedule_this(th, std::move(at));
        return ret;
    }

    template <typename R, typename Pred>
    auto async_task(ThreadID th, Ref<R>&&, Pred&&pred)
    {
        auto at     = std::make_unique<RefAttachedAsyncTasker<R,Pred>>(std::move(pred));
        auto ret    = at->future();
        schedule_this(th, std::move(at));
        return ret;
    }

    template <typename R, typename Pred>
    auto async_task(StdThread th, Ref<R>&&, Pred&&pred)
    {
        auto at     = std::make_unique<RefAttachedAsyncTasker<R,Pred>>(std::move(pred));
        auto ret    = at->future();
        schedule_this(th, std::move(at));
        return ret;
    }

}
