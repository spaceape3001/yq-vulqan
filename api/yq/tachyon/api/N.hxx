////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/N.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

namespace yq::tachyon {

    template <SomeSpatial T, typename ... Args>
    T*          И::create_spatial(Args&&... args)
    {
        Tachyon* t  = dynamic_cast<Tachyon*>(this);
        if(!t)
            return nullptr;
        T* sp   = t->create_child<T>(args...);
        if(!sp)
            return nullptr;
        t->subscribe(sp->id(), MG::Spatial);
        m_spatial   = *sp;
        return sp;
    }
    
    template <SomeSpatial T>
    T*          И::create_spatial(const typename T::MyMeta& mMeta)
    {
        Tachyon* t  = dynamic_cast<Tachyon*>(this);
        if(!t)
            return nullptr;
        T* sp   = t->create_child<T>(mMeta);
        if(!sp)
            return nullptr;
        t->subscribe(sp->id(), MG::Spatial);
        m_spatial   = *sp;
        return sp;
    }
}
