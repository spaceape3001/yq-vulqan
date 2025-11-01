////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
//#include <tachyon/api/UIElement.hpp>
//#include <type_traits>
//#include <cassert>
#include <concepts>

namespace yq::tachyon {

    template <typename Pred>
    auto Widget::apply_ui(UIElement* ui, Pred& pred)
    {
        if constexpr ( std::is_invocable_v<Pred, const UIElement&>)
            return pred(*ui);
        if constexpr ( std::is_invocable_v<Pred, UIElement&>)
            return pred(*ui);
        if constexpr ( std::is_invocable_v<Pred, const UIElement*>)
            return pred(ui);
        if constexpr ( std::is_invocable_v<Pred, UIElement*>)
            return pred(ui);
    }

    template <typename Pred>
    auto    Widget::for_elements(uint64_t bid, Pred&& pred) const
    {
        using result_t  = decltype(apply_ui(nullptr, pred));
        auto range  = m_ui.bids.equal_range(bid);
        for(auto itr = range.first; itr != range.second; ++itr){
            if(!itr->second)
                continue;
            if constexpr (!std::is_same_v<result_t, void>){
                result_t    res = apply_ui(itr->second, pred);
                if(res != result_t{})
                    return res;
            } else {
                apply_ui(itr->second, pred);
            }
        }
        if constexpr (!std::is_same_v<result_t, void>)
            return result_t{};
    }
    
    template <typename Pred>
    auto    Widget::for_elements(const std::string&uid, Pred&& pred) const
    {
        using result_t  = decltype(apply_ui(nullptr, pred));
        auto range  = m_ui.uids.equal_range(uid);
        for(auto itr = range.first; itr != range.second; ++itr){
            if(!itr->second)
                continue;
            if constexpr (!std::is_same_v<result_t, void>){
                result_t    res = apply_ui(itr->second, pred);
                if(res != result_t{})
                    return res;
            } else {
                apply_ui(itr->second, pred);
            }
        }
        if constexpr (!std::is_same_v<result_t, void>)
            return result_t{};
    }


#if 0
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(uint64_t id, std::function<RV(const U&)>&&fn) const
    {
        assert(fn && "Need to provide a valid function!");
            const U*    u;
            if constexpr (std::is_same_v<U,UIElement>){
                u   = itr->second;
            } else {
                u   = dynamic_cast<const U*>(itr->second);
            }
            if constexpr (!std::is_same_v<R,void>){
                RV   ret = fn(*u);
                if(ret != RV{})
                    return ret;
            } else {
                fn(*u);
            }
        }
        
        if constexpr (!std::is_same_v<R,void>)
            return RV{};
    }
    
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(uint64_t id, std::function<RV(const U*)>&&fn) const
    {
        assert(fn && "Need to provide a valid function!");
        auto range  = m_ui.bids.equal_range(id);
        for(auto itr = range.first; itr != range.second; ++itr){
            const U*    u;
            if constexpr (std::is_same_v<U,UIElement>){
                u   = itr->second;
            } else {
                u   = dynamic_cast<const U*>(itr->second);
            }
            if constexpr (!std::is_same_v<R,void>){
                RV   ret = fn(u);
                if(ret != RV{})
                    return ret;
            } else {
                fn(u);
            }
        }
        
        if constexpr (!std::is_same_v<R,void>)
            return RV{};
    }
#endif
    
    #if 0
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(uint64_t id, std::function<RV(U&)>&&fn) const;
    
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(uint64_t id, std::function<RV(U*)>&&fn) const;

    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(const std::string&, std::function<RV(const U&)>&&fn) const;
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(const std::string&, std::function<RV(const U*)>&&fn) const;
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(const std::string&, std::function<RV(U&)>&&fn) const;
    template <SomeUIElement U, typename RV>
    RV    Widget::for_elements(const std::string&, std::function<RV(U*)>&&fn) const;
    #endif
}
