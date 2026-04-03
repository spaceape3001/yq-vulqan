////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/AsyncTask.hxx>

namespace yq::tachyon {

#if 0
    struct Tachyon::LoadAPI {
        LoadContext&    context;
        //  TBD
    };
    
    struct Tachyon::SaveAPI {
        SaveContext&    context;
        //  TBD
    };

    struct Tachyon::LoadContext {
        // map of tachyons
    };
    
    struct Tachyon::SaveContext {
        // map of tachyons
    };
#endif

    ////////////////////////////////////////////
    //  Top-tachyon creates

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create(Args&&... args)
    {
        Ref<T>  tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp);
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create(const typename T::MyMeta& meta)
    {
        Ref<T> tp = dynamic_cast<T*>(meta.create()); // should *NEVER* fail unless uncreatable
        if(tp){
            retain(tp);
        }
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_on(use_thread_t ut, Args&&... args)
    {
        Ref<T>  tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp, ut);
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create_on(use_thread_t ut, const typename T::MyMeta& meta)
    {
        Ref<T> tp = dynamic_cast<T*>(meta.create()); // should *NEVER* fail unless uncreatable
        if(tp){
            retain(tp, ut);
        }
        return tp.ptr();
    }
     
    ////////////////////////////////////////////
    //  Child-tachyon creates


    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_child(Args&&... args)
    {
        Ref<T>   tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp);
        tp->_set_parent(*this);
        _add_child(*tp);
        return tp.ptr();
    }
    
    template <SomeTachyon T>
    T*   Tachyon::create_child(const typename T::MyMeta& meta)
    {
        Ref<T> tp = dynamic_cast<T*>(meta.create()); // should *NEVER* fail unless uncreatable
        if(tp){
            retain(tp);
            tp->_set_parent(*this);
            _add_child(*tp);
        }
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_child_on(use_thread_t ut, Args&&... args)
    {
        Ref<T>   tp  = new T(std::forward<decltype(args)>(args)...);
        tp -> m_flags |= F::DifferentThread;
        retain(tp, ut);
        tp->_set_parent(*this);
        _add_child(*tp);
        return tp.ptr();
    }


    template <SomeTachyon T>
    T*   Tachyon::create_child_on(use_thread_t ut, const typename T::MyMeta& meta)
    {
        Ref<T> tp = dynamic_cast<T*>(meta.create()); // should *NEVER* fail unless uncreatable
        if(tp){
            tp -> m_flags |= F::DifferentThread;
            tp->_set_parent(*this);
            _add_child(*tp);
            retain(tp, ut);
        }
        return tp.ptr();
    }

    ////////////////////////////////////////////
    //  Child-tachyon creates

    template <typename Pred>
    auto    Tachyon::tasker(StdThread th, Pred&& pred)
    {
        return async_task(th, this, std::move(pred));
    }
    
    template <typename Pred>
    auto    Tachyon::tasker(ThreadID th,  Pred&& pred)
    {
        return async_task(th, this, std::move(pred));
    }
}
