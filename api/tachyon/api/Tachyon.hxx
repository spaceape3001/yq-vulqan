////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/AsyncTask.hxx>

namespace yq::tachyon {

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
    T*   Tachyon::create(const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp);
        }
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_on(StdThread st, Args&&... args)
    {
        Ref<T>  tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp, st);
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create_on(StdThread st, const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp, st);
        }
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_on(ThreadID st, Args&&... args)
    {
        Ref<T>  tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp, st);
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create_on(ThreadID st, const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp, st);
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
    T*   Tachyon::create_child(const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp);
            tp->_set_parent(*this);
            _add_child(*tp);
        }
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_child_on(ThreadID st, Args&&... args)
    {
        Ref<T>   tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp, st);
        tp->_set_parent(*this);
        _add_child(*tp);
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_child_on(StdThread st, Args&&... args)
    {
        Ref<T>   tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp, st);
        tp->_set_parent(*this);
        _add_child(*tp);
        return tp.ptr();
    }


    template <SomeTachyon T>
    T*   Tachyon::create_child_on(ThreadID st, const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp, st);
            tp->_set_parent(*this);
            _add_child(*tp);
        }
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create_child_on(StdThread st, const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp, st);
            tp->_set_parent(*this);
            _add_child(*tp);
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
