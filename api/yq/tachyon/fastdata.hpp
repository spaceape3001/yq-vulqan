////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Frame.hpp>

namespace yq::tachyon {

    struct TypedID;
    
    template <typename T>
    const data_t<T>*  lastdata(ID<T> id)
    {
        const Frame* frame = Frame::current();
        if(!frame)
            return nullptr;
        return frame->data(id);
    }
    template <typename T>
    T*  pointer(ID<T> id)
    {
        const Frame* frame = Frame::current();
        if(!frame)
            return nullptr;
        return frame->object(id);
    }

    
    template <typename T>
    const snap_t<T>*  snapshot(ID<T> id)
    {
        const Frame* frame = Frame::current();
        if(!frame)
            return nullptr;
        return frame->snap(id);
    }
    
    inline TypedID  typed_for(TachyonID id)
    {
        const Frame* frame = Frame::current();
        if(!frame)
            return {};
        return frame->typed(id);
    }
}
