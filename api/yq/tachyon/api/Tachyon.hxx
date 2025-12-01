////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/AsyncTask.hxx>

namespace yq::tachyon {

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
        Ref<T> tp = static_cast<T*>(meta.create());
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
    T*   Tachyon::create_on(StdThread st, const typename T::MyMeta& meta)
    {
        Ref<T> tp = static_cast<T*>(meta.create());
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
    T*   Tachyon::create_on(ThreadID st, const typename T::MyMeta& meta)
    {
        Ref<T> tp = static_cast<T*>(meta.create());
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
    T*   Tachyon::create_child(const typename T::MyMeta& meta)
    {
        Ref<T> tp = static_cast<T*>(meta.create());
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
    T*   Tachyon::create_child_on(ThreadID st, const typename T::MyMeta& meta)
    {
        Ref<T> tp = static_cast<T*>(meta.create());
        if(tp){
            tp->_set_parent(*this);
            _add_child(*tp);
            retain(tp, st);
        }
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create_child_on(StdThread st, const typename T::MyMeta& meta)
    {
        Ref<T> tp = static_cast<T*>(meta.create());
        if(tp){
            tp->_set_parent(*this);
            _add_child(*tp);
            retain(tp, st);
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
