////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Mini.hpp>
#include <yq/tachyon/accessor/StringValue.hpp>
#include <yq/tachyon/accessor/TypedFunction.hpp>
#include <yq/text/format.hpp>

namespace yq::tachyon {
    class TextLabel : public Mini {
        YQ_TACHYON_DECLARE(TextLabel, Mini)
    public:
        
        using FN    = std::function<std::string_view()>;
    
        TextLabel();
        
        TextLabel(const char*);
        TextLabel(std::string_view);
        
        template <typename T>
        TextLabel(T v) requires (has_to_string_v<T> || has_to_string_view_v<T>)
        {
            accessor(SET, std::make_unique<StringValue>(v));
        }
        
        template <typename T>
        TextLabel(std::function<T()>&& fn)
        {
            accessor(SET, std::make_unique<TypedFunction<T>>(std::move(fn)));
        }

        TextLabel(AccessorUPtr&&);
        TextLabel(FN&&);
        
        using Mini::accessor;
        virtual void    accessor(set_k, AccessorUPtr&&) override;
        virtual void    imgui(ViContext&) override;

    private:
        ~TextLabel();

        StringAccessor* m_accessor  = nullptr;
    };
}

